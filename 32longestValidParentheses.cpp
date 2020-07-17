//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-valid-parentheses
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
//Solution:
//  Base solution: Do parentheses matching starting at each position
//                  then count the maximum anser.
//  Better solution: Dynamic programing
//  
using namespace std;
class Solution {
public:
    int longestValidParenthesesMy(string s) {
        if (s.empty())
            return 0;
        //DP array initialize
        int** dp = new int*[s.size()];
        for (int i = 0; i < s.size(); i++) {   
            dp[i] = new int[s.size()];
            memset(dp[i], 0, s.size() * sizeof(int));
        }
        // 无效代码，检查到这里很慢，基本没注意
        // for (int i = 0; i < s.size(); i++) {
        //     dp[i][i] = (s[i] == '(' ? '(' : ')');
        // }
        int maxLength = 0;
        //Iteration
        for (int l = 1; l < s.size(); l+=2) {    //set step to 2,cause valid length is odd
        //cout << "\nlength: " << l+1 << endl; 
            for (int i = 0; i < s.size() - l; i++) {
                //cout << i << "." << endl;
                int j = i + l;
                //  (dp[i][i+l/2] == 1 && dp[i+l/2+1][j]==1) can't conclude all situation, cause connect point may not be at middle
                if (s[i] == '(' && s[j] == ')' && (l==1 || (l > 1 && dp[i+1][j-1] == 1))) { // (.*)
                    dp[i][j] = 1;
                    maxLength = l+1;
                    i++;
                }
                else {  // iterate over all possible connection ().*
                    for (int subL = 1; subL < l; subL++) {
                        //cout << "dp[" << i << "][" << subL << "]:dp[" << subL+1 << "][" << j << "]  " << dp[i][i+subL] << ":" << dp[i+subL+1][j] << endl;
                        // index error
                        if (dp[i][i + subL] == 1 && dp[i+subL+1][j] == 1) {
                            dp[i][j] = 1;
                            maxLength = l+1;
                            i++;
                        }
                    }
                }
                //cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
            }
        //cout << "maxlength: " << maxLength << endl;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {

            }
            else {
                
            }
        }
        return maxLength;
    }
    // conclusion: my understanding of DP is not flexible enough
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

int main()
{
    //string s = "()()()()";
    //string s = "((()))";
    //string s = "()(())((";
    //string s;
    //string s = ")()())";
    //string s = ")(()())";
    //string s = ")(((((()())()()))()(()))(";
    //string s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    string s = "(()(()()()(()())()(()()))()()())()(((()())((())(()()((()((((())(())()()(())()(()(()(())))))))(()()()))()()))))))(()())))((())())))()(((()(()))())((())))(())(((()()))))())))((()((()()(()))())(()))(())((())()(((()(((()))))()))()()())()()()(()(()(()()()(()(())(())))())()))())(())((())(()((((())((())((())(()()(((()))(()(((())())()(())))(()))))))(()(()(()))())(()()(()(((()()))()(())))(()()(())))))(()(()()())))()()())))))((())(()()(((()(()()))(())))(((()))())())())(((()((()((()())((()))(()()((()(())())(()))()())())))))()(()())))()()))(((()(()))((()((((())((())))((())()()))())()(((()()(((()))))))(((()))()(()(((())(())()()()))))()))()))))()(()))()()()))))()(()))()()(()())))(()))()())(())()())(())()()))(()())))((()())))())))))((()))())()()))))()))(((())(())()))()()((()))(((()))))((()((()))(())(((()))()()()())())())))(()(((())()())(())(((()()((())()))(()()(((())))((()(((()))(((((()(((())())))(())(()()((()(()(())())(((((())((()()))())(()())))()()()(()(((((((())))(()()()()((()(((())())())())))())())())))()((((())(((()()()())()))()()(()(()()))()))(())(()())))))()())()())))()()(())))))))((())()()(((()))()))())))))((()())((()())(((())()())()))(()(()()(((()(())()))()())()()(())()(()))))()))()()))))(())(()()(())((()))(()))((())))))(())))()))(()()(())))())()((())()))((()()(()())()()(()))())(((())()(((()((())()(()()()((()(()())(()())())((((())))())())))(()))(((())((()))))((()()(((())((())()()()))((()())()()())())))))((((()((()())))(())(())()()()(((((())())()()()(())())()((()(()())(((())((((()((()(((()))(()()))())()()(()(()(())))()))())))(()()(()))))))(()()())()()))()(())()(";
    cout << Solution().longestValidParentheses(s);
    return 0;
}