#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        else if (x > 0x7FFEA810) {
            return 46340;
        }
        int bond = x / 2 + 1;
        bond = x > 46340 ? 46340 : bond;
        int i;
        for (i = bond; i > 0; i--) {
            int result = i * i;
            //cout << i << endl;
            if (result == x) {
                cout << "1st" << endl;
                return i;
            }
            else if(result < x) {
                //cout << "2nd" << endl;
                return i;
            }
            else {}
        }
        //cout << "3rd" << endl;
        return i;
    }
};