class Solution {
private:
    double findMedianOfOne(vector<int>& nums) {
        return (nums.size() % 2) == 0 ? ((nums[(nums.size()/2)-1] + nums[nums.size()/2]) / 2.0) :
            nums[nums.size()/2] ;
    }
    double whenNotIntersect(vector<int>& bigger, vector<int>& little) {
        
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {    //前两个if处理两个数组中一个为空的情况（题目已假设两个数组不同时为空）
            return this->findMedianOfOne(nums2);
        }
        else if (nums2.empty()) {  
            return this->findMedianOfOne(nums1);
        }
        else {  //两个数组都不为空
            int size1 = nums1.size();
            int size2 = nums2.size();

            if (nums1.back() > nums2.front()) {
                if (size1 > size2) {
                    int differ = size1 - size2;
                    return (differ % 2 == 0) ? ((nums1[(size1 - 1 + (differ-1)) / 2 + nums1[(size1 - 1 + (differ-1)) / 2 + 1]]) / 2.0)
                        : nums1[(size1 - 1 + (differ-1)) / 2];
                }
                else if (size1 < size2){
                    int differ = size2 - size1;
                    return (differ % 2 == 0) ? ()
                }
            }
            else if (nums2.back() > nums1.front()) {
                
            }
            else {

            }
            double mid1 = findMedianOfOne(nums1);
            double mid2 = findMedianOfOne(nusm2);
            if (mid1 > mid2) {
                
            }
            else if (mid1 < mid2) {

            }
            else {
                return mid1;
            }

        }
    }
};