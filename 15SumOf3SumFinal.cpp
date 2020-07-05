#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int nsize = nums.size();
        int target;
        int last = 0x80000000; //indicate not valid number
        //int countloop = 1;
        for (int i = 0; i < nsize-2; i++) {
            //cout << " i:" << i << " last:" << last << " nums[i]:"  << nums[i] << endl;
            if (nums[i] != last) {
                last = nums[i];
                target = -last;

                int l = i + 1;
                int r = nsize - 1;
                //int countloop2 = 1;
                int llast = 0x80000000; // avoid 2nd number repeat
                while (l < r) {
                    //cout << "2:" << countloop2++ << " l:" << l << " r:" << r << endl;
                    if (nums[l] + nums[r] > target) {
                        r--;
                    }
                    else if (nums[l] + nums[r] < target) {
                        l++;
                    }
                    else {
                        if (nums[l] != llast) {
                            llast = nums[l];

                            //cout << "GET:" << last << ":" << nums[l] << ":" << nums[r] << endl;
                            result.push_back(vector<int>({last, nums[l], nums[r]}));
                        }
                        else {}
                        l++;
                        r--;
                    }
                }
            }
            else { }// do nothing
        }
        return result;
    }
};