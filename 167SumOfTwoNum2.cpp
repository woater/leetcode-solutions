#include <vector>

using namespace std;

class Solution {
private:
    int BinarySearch(const vector<int>& sortedArray, int target, int left, int right) {
        //int left = 0;
        //int right = sortedArray.size()-1;
        
        int mid = (left + right) / 2;
        while (left != right) {
            if (sortedArray[mid] > target) {
                right = mid;
            }
            else if (sortedArray[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return left; //need called to confirm if finded, just test sortedArray[left] == target
    }
public:
    vector<int> twoSumV1(vector<int>& numbers, int target) { // O(n)
        int l = 0, r = numbers.size()-1;
        int sum;
        while (l != r) {
            sum = numbers[l] + numbers[r];
            if (sum > target) {
                r--;
            }
            else if (sum < target) {
                l++;
            }
            else {
                return vector<int>({l+1, r+1});
            }
        }
        return vector<int>(l+1, 2);
    }
    vector<int> twoSum(vector<int>& numbers, int target) {// 废七八力的想了一个O(nlogn算法)？？？？？耻辱柱订好了
        int nsize = numbers.size();
        for (int l = 0; l < nsize; l++) {
            int differ = target - numbers[l];
            int r = BinarySearch(numbers, differ, l+1, nsize-1);
            if (differ == numbers[r]) {
                return vector<int>({l, r});
            }
            else {}
        }
        return vector<int>();
    }
};