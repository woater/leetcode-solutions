#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;

        //使用简单数组可以缩短运行时间
        /*
        int modui[13] =    {1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,   1};
        char* moduc[13] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV","I"};
        */
        vector<int> modui = {1000, 900, 500, 500, 100, 90, 50, 50, 10, 9, 5, 4, 1};
        vector<string> moduc = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV","I"};
        for (int i = 0; i < 13; i++) {
            int decre = num / modui[i];
            num -= decre;
            cout << num << endl;
            for (int j = 0; j < decre; j++) {
                result += moduc[i];
            }
        }
        return result;
    }
};