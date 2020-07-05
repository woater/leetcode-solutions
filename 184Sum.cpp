#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nsize = nums.size();
        if (nsize < 4) 
            return vector<vector<int>>(); 
        else;

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int ibond = nsize - 3; // avoid minus operation
        int jbond = nsize - 2; // avoid minus operation

        int lasti = 0x80000000;
        int lastj;
        int lastl;
        for (int i = 0; i < ibond; i++) {
            while (i < ibond && nums[i] == lasti)
                i++;
            lasti = nums[i];

            lastj = 0x80000000;
            for (int j = i + 1; j < jbond; j++) {
                while (j < jbond && nums[j] == lastj)
                    j++;
                lastj = nums[j];

                int l = j + 1;
                int r = nsize - 1;
                while (l < r) {
                    int thisSum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (thisSum > target)
                        r--;
                    else if (thisSum < target)
                        l++;
                    else {
                        ans.push_back(vector<int>({nums[i], nums[j], nums[l], nums[r]}));

                        lastl = nums[l];
                        while (l < r && nums[l] == lastl)
                            l++;
                    } 
                }

            }
        }
        return ans;
    }
};