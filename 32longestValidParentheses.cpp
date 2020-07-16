//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-valid-parentheses
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
//Solution:
//  Base solution: Do parentheses matching starting at each position
//                  then count the maximum anser.
//  Better solution: Dynamic programing
//  
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        //DP array initialize
        int** dp = new int*[s.size()];
        for (int i = 0; i < s.size(); i++) {   
            dp[i] = new int[s.size()];
            memset(dp[i], 0, s.size() * sizeof(int));
        }
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = (s[i] == '(' ? '(' : ')');
        }
        int maxLength = 0;
        //Iteration
        for (int l = 1; l < s.size(); l+=2) {    //set step to 2,cause valid length is odd
        cout << "l: " << l << endl; 
            for (int i = 0; i < s.size() - l; i++) {
                int j = i + l;
                //  (dp[i][i+l/2] == 1 && dp[i+l/2+1][j]==1) can't conclude all situation, cause connect point may not be at middle
                if (s[i] == '(' && s[j] == ')' && (l==1 || (l > 1 && dp[i+1][j-1] == 1))) {
                    dp[i][j] = 1;
                    maxLength = l+1;
                }
                else {  // iterate over all possible connection
                    for (int subL = 1; subL < l; subL+=2) {
                        if (dp[i][subL] == 1 && dp[subL+1][j] == 1) {
                            dp[i][j] = 1;
                            maxLength = l+1;
                            break;
                        }
                    }
                }
            }
        cout << "maxlength: " << maxLength << endl;
        }
        return maxLength;
    }
};

int main()
{
    //string s = "()()()()";
    //string s = "((()))";
    string s = "()(())((";
    cout << Solution().longestValidParentheses(s);
    return 0;
}