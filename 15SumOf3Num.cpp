#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int vk = -(nums[i] + nums[j]);
                int il = 0, ir = nums.size();
                int k, mid;
                while (il != ir) {
                    mid = (il + ir) / 2;
                    if (nums[mid] > vk) {
                        il = mid + 1;
                    } else if (nums[mid] < vk) {
                        ir = mid;
                    } else {
                        k = mid;
                        break;
                    }
                }
                
            }
        }
    }
};