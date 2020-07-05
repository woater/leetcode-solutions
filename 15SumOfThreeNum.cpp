#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
private:
    //assume size of nums2 is smaller or equal to nums1
    //using hash_map
    bool redundant(const vector<int>& nums1, const vector<int>& nums2, int sameLimit) {
        unordered_set<int> info2;
        int nsame = 0;
        for(auto i : nums2) {
            info2.insert(i);
        }
        for(auto i : nums1) {
            if (info2.find(i) != info2.end()) {
                nsame++;
            }
        }
        bool result = (nsame < sameLimit) ? false : true;
        //cout << result << " with " << nsame << endl;
        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        cout << "what?" << endl;
        int numSize = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < numSize; i++) {
            int iv = nums[i];
            for (int j = i + 1; j < numSize; j++) {
                int ij = nums[j];
                for (int k = j + 1; k < numSize; k++) {
                    if ((iv + ij) == (-nums[k])) {
                        cout << "innerest" << endl;
                        vector<int> tempVi{iv, ij, nums[k]};
                        bool duplicated = false;
                        for (auto vi : result) {
                            if (redundant(vi, tempVi, 3) ) {
                                duplicated = true;
                            } else {} // do nothing
                        }
                        if (!duplicated) {
                            result.push_back(tempVi);
                        } else {}
                        
                    }
                }
            }
        }
        return result;
    }
};