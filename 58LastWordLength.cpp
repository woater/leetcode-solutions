#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        int length = 0;
        bool countinue = false;

        for (int i = 0; i < s.size(); i++) {
            if (isalpha((int)s[i])) {
                if (countinue) {
                    length++;
                }
                else {
                    countinue = true;
                    length = 1;
                }
            }
            else {
                countinue = false;
            }
        }
        return length;
    }
};