#include <vector>
using namespace std;
// Demand:
// given an element search it in O(logn) time

// Solution:
// binary search
// how to deal with rotation ?
//  in each search, compare middle element with it's two negithbors
//  if not ascending order
//  then this is the pivot

// Code:
class Solution {
public:
    int binarySearchWithRotate(vector<int>& nums, size_t begin, size_t end, int target) {
        if (begin == end) {
            if (nums[begin] == target)
                return begin;
            else
                return -1;
        }

        size_t mid = (begin + end) / 2;
        if (nums[mid] == target)    // find
            return mid;

        if (mid > 0 && mid < (nums.size()-1)) { // mid isn't begin or end point
            if (nums[mid] > nums[mid-1]) { // mid isn't the min value
                if (nums[mid] < nums[mid+1]) {// mid+1 isn't the min value
                    if (nums[mid] > target) {
                        return binarySearchWithRotate(nums, begin, mid, target);
                    }
                    else if (nums[mid < target]) {
                        return binarySearchWithRotate(nums, mid+1, end, target);
                    }
                }
                else {  // mid+1 is the min value
                    if (nums[0] > target) {
                        return binarySearchWithRotate(nums, mid+1, end, target);
                    }
                    else {
                        return binarySearchWithRotate(nums, begin, mid, target);
                    }
                }
            }
            else { // mid is the min value
                    if (nums[0] > target) {
                        return binarySearchWithRotate(nums, mid, end, target);
                    }
                    else {
                        return binarySearchWithRotate(nums, begin, mid-1, target);
                    }
            }
        }
        else { // mid is begin or end point and mid is not position
            if (nums[mid] < target && mid == begin) {
                if (nums[mid+1] == target)
                    return mid+1;
            }
            else if (nums[mid] > target && mid == end) {
                if (nums[mid-1] == target)
                    return mid-1;
            }
            return -1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() < 3) {
            if (nums[0] == target)
                return 0;
            else if (nums.size() == 2 && nums[1] == target)
                return 1;
            else
                return -1;
        }
        else {
            return binarySearchWithRotate(nums, 0, nums.size()-1, target);
        }
    }
};