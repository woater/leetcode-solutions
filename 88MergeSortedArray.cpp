#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty())
            return;

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        vector<int>::iterator end2 = nums2.end();


        if (*it1 != 0) {
            bool postZero = true;//0之前是否有非0元素

            while (it2 != end2) {
                if (*it2 <= *it1) {
                    it1 = nums1.insert(it1, *it2);
                    it1++;  //Move to next position of inserted element[]
                    it2++;
                    postZero = true;
                }
                else if (postZero && *it1 == 0){
                    break;
                }
                else {
                    it1++;
                }
            }
        }
        else {
            nums1 = nums2;
            return;
        }
        while (it2 != end2) {
            *it1 = *it2;
            it1++;
            it2++;
        }
        while (*it1 == 0) {
            it1 = nums1.erase(it1) - 1;
        }
    }
};