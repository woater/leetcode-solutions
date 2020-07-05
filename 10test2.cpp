#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int m = s.size(),n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(false, n+1));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; i <= n; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    if (s[i-1] != p[j-2] && p[j-2] != '.') {
                        dp[i][j] = dp[i][j-2];
                    }
                    else {
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                }
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    if(s[i-1] != p[j-2] && p[j-2] != '.')
                        dp[i][j] = dp[i][j-2];
                    else{
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    string s = "aa";
    string p = "a";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}