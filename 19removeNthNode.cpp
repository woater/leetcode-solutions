#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromBeginning(ListNode* head, int n) { // from beginning
        ListNode* lastNode = NULL;
        ListNode* thisNode = head;

        if (n != 0) {
            for (int i = 1; i <= n && thisNode != NULL; i++) { // until thisNode point to target node
                lastNode = thisNode;
                thisNode = thisNode->next;
            }
            if (thisNode != NULL) {
                lastNode->next = thisNode->next;
                delete thisNode;
                return head;
            }
            else {
                return head;
            }
        }
        else {
            ListNode* nextNode = head->next;
            delete head;
            return nextNode;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tryLength = head;
        int cntLnth = 0;
        while (tryLength != NULL) {
            tryLength = tryLength->next;
            cntLnth++;
        }
        return removeNthFromBeginning(head, cntLnth-n);
    }
};