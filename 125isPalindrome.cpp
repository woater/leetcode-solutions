#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    bool isAlphaAndCapIt(char& c) {
        if (c >= 'a' && c <='z') {
            return c-=32;
        }
        else if(c >= 'A' && c <= 'Z') {
            return 2;
        }
        else {
            return 0;
        }
    }    
public:
    bool isPalindrome(string s) {
        int ssize = s.size();
        for (int l = 0, r = ssize - 1; l != r; l++, r--) {
            bool ljg = isAlphaAndCapIt(s[l]);
            bool rjg = isAlphaAndCapIt(s[r]);
            if (ljg && rjg) {
                //cout << s[l] << " : " << s[r] << endl;
                if (s[l] != s[r]) {
                    return false;
                }
                else {} // do nothing;
            }
            else if (!ljg && !rjg) {
                r++;
                l--;
            }
            else if (!ljg) {
                r++;
            }
            else {
                l--;
            }
        }
        return true;
    }
};

int main()
{
    string s = "race a car";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}