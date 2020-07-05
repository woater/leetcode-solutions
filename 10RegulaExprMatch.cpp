#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slength = s.size();
        int plength = p.size();

        int j = 0, i;
        int count  = 1;
        int margin = 0;
        //bool preDotStar = false;
        for (i = 0; i < slength; i++) {
            //cout << "[" << (count++) << "]" << " i:" << i << " j:" << j << endl;
            switch (p[j]) 
            {
            case '.':   //它谁都可以，不管他了
                j++;
                break;
            case '*':
                if (j > 0 && (s[i] == p[j-1] || p[j-1] == '.')) { //处理*一般情况
                //     if (p[j-1] == '.' && (!preDotStar)) {
                //         margin +=2;
                //         preDotStar = true;
                //     }
                //     else {
                //         margin++;
                //         if (p[j-1] != '.') {
                //             preDotStar = false;
                //         }
                //         else {}
                //     }
                    margin++;
                    if (p[j-1] == '.') {
                        char c = s[i];
                        while (s[i] == c) {
                            //cout << "jumping..." << " i: " << i << " c: " << c << endl;
                            i++;
                            margin++;
                        }
                        //cout << "jumping complete: " << " i: " << i << " c: " << s[i] << endl;
                        i--;
                        j++;
                    }
                    else {} // do nothing
                }
                else if (j < (plength - 1) &&(s[i] == p[j+1] || p[j+1] == '.')) {   //越过无效*
                    j+=2;
                }
                else {  //不匹配
                    if ( j > 0 && i > 0 && p[j] == '*' && p[j-1] == s[i-1]) {   //前置*，去除前置重复项
                        j++;
                        while (p[j] == s[i-1]) {
                            j++;
                        }
                        i--;
                    }
                    else {
                        cout << "f1" << endl;
                        return false;
                    }
                }
                break;
            default:    //普通情况
                if (s[i] != p[j]) {
                    if (j < (plength - 1) && p[j+1] == '*') {
                        j+=2;
                        i--;
                    }
                    else {
                        cout << "f2" << endl;
                        return false;
                    }
                }
                else {
                    j++;
                } // do nothing
            }
        }

        //cout << "first part complete." << " i: " << i << " j: " << j << endl;
        //cout << "margin: "<< margin << endl;

        //bool preStar = false; //用来记录前置*，用裕度值margin代替
        while (j < plength) {
            //cout << "j[" << j << "]" << endl;
            if (p[j] == '*') { //越过*
                //preStar = true;
                j++;
            }
            else if (j < (plength-1) && p[j+1] == '*') {    //越过字符+*
                //preStar = true;
                j+=2;
            }
            //else if (j > 1 && (p[j-1] == '*' && (p[j-2] == p[j] || p[j-2]=='.'))){
            else if (j > 1 && p[j-1] == '*' && p[j-2] == p[j]){    //越过前置*后置相同字符
                //preStar = false;
                j++;
            }
            // else if (j == plength - 1 && p[j] == s[i-1]) {
            //     return true;
            // }
            //else if (preStar && (p[j] == s[i-1] || p[j] == '.') && margin > 0) {
            else if (margin > 0 ) { //遇到实字符
                if (p[j] == '.') {
                    //preStar = false;
                    margin--;
                    j++;
                }
                else {
                    bool find = false;
                    for (int k = slength - margin; k < slength; k++) {
                        //cout << "k:" << k << endl;
                        if (p[j] == s[k]) {
                            margin--;
                            find = true;
                            break;
                        }
                        else {}
                    }
                    if (! find) {
                        cout << "f3" << endl;
                        return false;
                    }
                    else {
                        j++;
                    } // do nothing
                }
            }
            else {
                cout << "f4" << endl;
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "aab";
    string p = "c*a*b";
s = "aasdfasdfasdfasdfas";
p = "aasdf.*asdf.*asdf.*asdf.*s";
    cout << "s: " << s.length() << " p: " << p.length() << endl;
    cout << Solution().isMatch(s, p) << endl;
    //while (getchar() != 'q');
    return 0;
}