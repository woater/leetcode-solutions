#include <vector>

using namespace std;

//摩尔投票算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int cadidate;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                cadidate = nums[i];
                cnt = 1;
            }
            else if (nums[i] == cadidate)
                cnt++;
            else
                cnt--;
        }
        return cadidate;
    }
};