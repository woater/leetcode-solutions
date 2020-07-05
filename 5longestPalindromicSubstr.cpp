#include <string>
#include <vector>

using namespace std;

#define MAXLENGTH 1000

class Solution1 { //27.93% & 37.01%
public:
    string longestPalindrome(string s) {
        int ssize = s.size();
        if (ssize == 0) {   //不知道是否有必要做该检查------待验证
            return s;
        }
        else {} // do nothing
        //save index of longest sub string
        int maxL = 0;
        int maxR = 0;
        int maxLengthMinus1 = 0;

        //new information array
        bool **info = new bool* [ssize];
        for (int i = 0; i < ssize; i++) {
            info[i] = new bool [ssize];
            for (int j = 0; j < ssize; j++) {
                info[i][j] = false;
            }
        }
        //assign info[i][i] to be 1, because one element is palindrmmic
        for (int i = 0; i < ssize; i++) {
            info[i][i] = true;
        }
        //间距
        for (int k = 1; k <= ssize - 1; k++) {
            //左端比较位置
            for (int i = 0; i < ssize - k; i++) {
                //两相邻元素对称或中间元素相对称
                if (s[i] == s[k+i] && (k == 1 || info[i+1][k+i-1])) { 
                    info[i][k+i] = true;
                    if (k > maxLengthMinus1) {
                        maxLengthMinus1 = k;
                        maxL = i;
                        maxR = i + k;
                        //cout << s.substr(maxL, k+1) << endl;
                        //cout << "L:" << s[i] << "R:" << s[i+k] << endl;
                    }
                    else {}
                }
                else {}
            }
        }

        return s.substr(maxL, maxLengthMinus1+1);

        //delete information array
        for(int i = 0; i < ssize; i++) {
            delete [] info[i];
        }
        delete [] info;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int ssize = s.size();
        if (ssize == 0) {   //有必要进行确认，后续分配数组无法分配0空间数组
            return s;
        }
        else {} // do nothing
        //save index of longest sub string
        int maxL = 0;
        int maxLengthMinus1 = 0;

        //new information array
        bool **info = new bool* [ssize];
        for (int i = 0; i < ssize; i++) {
            info[i] = new bool [ssize];
            for (int j = 0; j < ssize; j++) {
                info[i][j] = false;
            }
        }
        //assign info[i][i] to be 1, because one element is palindromic
        for (int i = 0; i < ssize; i++) {
            info[i][i] = true;
        }
        //间距
        for (int k = 1; k <= ssize - 1; k++) {
            //左端比较位置
            for (int i = 0; i < ssize - k; i++) {
                //两相邻元素对称或中间元素相对称
                if (s[i] == s[k+i] && (k == 1 || info[i+1][k+i-1])) { 
                    info[i][k+i] = true;
                    if (k > maxLengthMinus1) {
                        maxLengthMinus1 = k;
                        maxL = i;
                        //cout << s.substr(maxL, k+1) << endl;
                        //cout << "L:" << s[i]  << endl;
                    }
                    else {}
                }
                else {}
            }
        }

        return s.substr(maxL, maxLengthMinus1+1);

        //delete information array
        for(int i = 0; i < ssize; i++) {
            delete [] info[i];
        }
        delete [] info;
    }
};