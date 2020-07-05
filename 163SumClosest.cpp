#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         int minResult = 0x7fffffff;

//     }
//     vector<vector<int>> threeSum(vector<int>& nums, int sumTarget) {
//         vector<vector<int>> result;

//         sort(nums.begin(), nums.end());
//         int nsize = nums.size();
//         int target;
//         int last = 0x80000000; //indicate not valid number
//         //int countloop = 1;
//         for (int i = 0; i < nsize-2; i++) {
//             //cout << " i:" << i << " last:" << last << " nums[i]:"  << nums[i] << endl;
//             if (nums[i] != last) {
//                 last = nums[i];
//                 target = -last;

//                 int l = i + 1;
//                 int r = nsize - 1;
//                 //int countloop2 = 1;
//                 int llast = 0x80000000; // avoid 2nd number repeat
//                 while (l < r) {
//                     //cout << "2:" << countloop2++ << " l:" << l << " r:" << r << endl;
//                     if (nums[l] + nums[r] > target) {
//                         r--;
//                     }
//                     else if (nums[l] + nums[r] < target) {
//                         l++;
//                     }
//                     else {
//                         if (nums[l] != llast) {
//                             llast = nums[l];

//                             //cout << "GET:" << last << ":" << nums[l] << ":" << nums[r] << endl;
//                             result.push_back(vector<int>({last, nums[l], nums[r]}));
//                         }
//                         else {}
//                         l++;
//                         r--;
//                     }
//                 }
//             }
//             else { }// do nothing
//         }
//         return result;
//     }
// };

#define myAbs(x) ((x)>0?(x):(-(x)))

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        //unique(nums.begin(), nums.end());
        int nsize = nums.size();
        int bestDist = 0x7fffffff;  //record best result
        int bestSum;
        int last = 0x80000000; // record last element
        int thisSum;
        int thisDist;
        for (int i = 0; i < nsize-2; i++) {
            if (nums[i] != last) {
                last = nums[i];

                int l =  i+1;
                int r = nsize - 1;
                while (l != r) {
                    thisSum = nums[i] + nums[l] + nums[r];
                    thisDist = myAbs(thisSum - target);
                    cout << "thisSum: " << thisSum << " thisDist: " << thisDist << endl;
                    if (thisDist == 0) return target; else {}
                    if (thisDist < bestDist) {
                        bestSum = thisSum;
                        bestDist = thisDist;
                    } else {} 
                    if (thisSum > target) {
                        r--;
                    }
                    else {
                        l++;
                    }
                }
            }
        }
        return bestSum;
    }
};