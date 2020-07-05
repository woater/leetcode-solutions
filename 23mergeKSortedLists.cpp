#include <vector>
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> ansVec;
        while (lists.size() != 0) {
            //cout << "listsize: " <<  lists.size() << endl;
            int iOfTarget=-1;   //record minimun node
            int minval = 0x7fffffff; //minimun value of type int
            //ought to be maximun value of int, but set to minimun value ,cause runtime error

            for (int i = 0; i < lists.size(); i++) {
                ////cout << "test of overflow: loop1: [" << i <<  "]" <<endl;
                while (i < lists.size() && lists[i] == NULL) {
                    //cout << "erase" << endl;
                    lists.erase(lists.begin() + i);
                }
                ////cout << "before first if" << endl;
                if (lists[i] != NULL && lists[i]->val < minval) {
                    iOfTarget = i;
                    minval = lists[i]->val;
                    //cout << "get minval: " << minval;
                } else;
            }
            ////cout << "end of first part1" << endl;
            if (iOfTarget >= 0) {
                ansVec.push_back(lists[iOfTarget]);// runtime error
                lists[iOfTarget] = lists[iOfTarget]->next;
                //cout << "target: " << lists[iOfTarget] << endl;
            }
            ////cout << "end of first part2" << endl;
        }
        if (ansVec.size() == 0) {
            return NULL;
        }
        else {
            ListNode* ans = ansVec[0];
            ListNode* posi = ans;
            for (int i = 1; i < ansVec.size(); i++) {
                //cout << "test of overflow: loop2: [" << i << "]" <<  endl;
                posi->next = ansVec[i];
                posi = posi->next;
            }
            posi->next = NULL;
            return ans;
        }
    }
};