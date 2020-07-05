#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ssize = s.size();
        int times = 1;
        int result = 0;
        for (int i = ssize - 1; i > 0; i--) {
            result += ((int)(s[i] - 'A' + 1)) * times;
            times *= 26;
        }
        result += ((int)(s[0] - 'A' + 1)) * times;
        return result;
    }
};
// a shorter but almost same code
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};