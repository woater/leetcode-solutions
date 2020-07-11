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
    int binarySearch(vector<int>& nums, size_t begin, size_t end, int target) {
        //cout << begin << ":" << end << endl;
        if (begin == end)
            return nums[begin] == target ? begin : -1;
        size_t mid = (begin + end) / 2;
        //cout << mid << endl;
        if (nums[mid] > target) {
            return binarySearch(nums, begin, mid, target);
        }
        else if (nums[mid] < target) {
            return binarySearch(nums, mid+1, end, target);
        }
        else {
            return mid;
        }
        return -1; // default return value
    }
    int binarySearchWithRotate(vector<int>& nums, size_t begin, size_t end, int target) {
        //cout << begin << ":" << end << endl;
        if (begin == end) {
            if (nums[begin] == target)
                return begin;
            else
                return -1;
        }

        size_t mid = (begin + end) / 2;
        if (nums[mid] == target)    // find
            return mid;

        if (mid > begin && mid < end) { // mid isn't begin or end point
            if (nums[mid] > nums[mid-1]) { // mid isn't the min value
                if (nums[mid] < nums[mid+1]) { // not find mid value
                    int lv = binarySearchWithRotate(nums, begin, mid, target);
                    int rv = binarySearchWithRotate(nums, mid+1, end, target);
                    return lv > rv ? lv : rv;
                }
                else {  // mid+1 is the min value
                    //cout << "find mid+1" << mid + 1 << endl;
                    if (nums[0] > target) {
                        return binarySearch(nums, mid+1, end, target);
                    }
                    else {
                        return binarySearch(nums, begin, mid, target);
                    }
                }
            }
            else { // mid is the min value
                    //cout << "find mid" << mid << endl;
                    if (nums[0] > target) {
                        return binarySearch(nums, mid, end, target);
                    }
                    else {
                        return binarySearch(nums, begin, mid-1, target);
                    }
            }
        }
        else { // mid is begin or end point and mid is not positioned
            if (nums[begin] == target)
                return begin;
            else if (nums[end] == target)
                return end;
            else
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