#include <vector>
#include <iostream>

#define myMax(x,y) ((x)>(y)?(x):(y))
#define myMin(x,y) ((x)<(y)?(x):(y))
using namespace std;

class Solution {
private:
    int naiveAlgo(vector<int>& height) {        //O(n^2）--overtime
        int result = 0;
        int temp;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                temp = myMax(height[i], height[j]) * (j-i);
                result = myMax(result, temp);
            }
        }
        return result;
    }
    int betterAlgo(vector<int>& height) {   //遍历更高效，与左右两侧高度相关
        int result = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * myMin(height[i], height[j]);
            result = myMax(result, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
public:
    int maxArea(vector<int>& height) {
        //int hsize = height.size();
        //vector<vector<int>> info(hsize, vector<int>(hsize));
        return naiveAlgo(height);
    }  
};