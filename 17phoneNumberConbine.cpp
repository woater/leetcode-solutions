#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> lastans;
        int digsize = digits.size();
        string temps;
        if (digsize == 0) 
            return vector<string>(); else;
        map<char, string> M = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        //储存最后一位数字所代表的情况
        for (int i = 0; i < M.find(digits[digsize-1])->second.size(); i++) {
            temps = string();
            temps.push_back(M[digits[digsize-1]][i]);
            ans.push_back(temps);
        }
        //倒序进行
        for (int iofdigits = digsize - 2; iofdigits >= 0; iofdigits--) { //对digits每位进行
            //cout << "first: " << digits[iofdigits] << endl;
            lastans = ans;
            ans = vector<string>();
            for (int iofthisdig = 0; iofthisdig < M.find(digits[iofdigits])->second.size(); iofthisdig++) {//对当前数字的每个字母进行
                //cout << "second: " << M.find(digits[iofdigits])->second[iofthisdig] << endl;
                temps = string();
                temps.push_back(M.find(digits[iofdigits])->second[iofthisdig]);
                for (int iofans = 0; iofans < lastans.size(); iofans++) { //对前一答案每一string进行
                    //cout << "third: " << lastans[iofans] << endl;
                    ans.push_back(temps + lastans[iofans]);
                }
            }
        }
        return ans;

    }
};