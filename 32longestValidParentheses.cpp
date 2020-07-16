//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-valid-parentheses
#include <string>
#include <vector>

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
        for (int l = 0; l < s.size(); l+=2) {    //set step to 2,cause valid length is odd
            for (int i = 0; i < s.size() - l - 1; i++) {
                int j = i + l;
                if ((s[i] == '(' && s[j] == ')' && (l==1 || (l > 1 && dp[i+1][j-1] == 1))) || (dp[i][i+l/2] == 1 && dp[i+l/2+1][j]==1)) {
                    dp[i][j] = 1;
                    maxLength = l;
                }
            }
        }
        return maxLength;
    }
};