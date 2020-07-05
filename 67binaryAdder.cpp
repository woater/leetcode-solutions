#include <string>
#include <iostream>

#define myMax(a,b) ((a) > (b) ? (a) : (b))
#define myMin(a,b) ((a) < (b) ? (a) : (b))

using namespace std;
// class Solution {
// private:
//     inline bool charToLogic(char c) {    // not detect validity assuming all input is '1' or '0'
//         if (c == '1') {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
//     inline char logicToChar(bool b) {
//         return b ? '1' : '0';
//     }
//     inline bool myXor(bool a, bool b) {
//         return a != b;
//     }
//     void onePlus(string s, int n, string& result, bool& carry) {
//         while (carry && n >= 0) {
//             if (s[n] == '1') {
//                 n--;
//                 result.insert(result.begin(), 1, '0');
//             }
//             else {
//                 n--;
//                 result.insert(result.begin(), 1, '1');
//                 carry = false;
//             }
//             cout << "final carry:" << carry << endl;
//         }
//         if (carry) {
//             cout << "Final carry" << endl;
//             result.insert(result.begin(), 1, '1');
//         }
//         else {
//             while (n >= 0) {
//                 result.insert(result.begin(), 1, s[n--]);
//             }
//         }
//     }
// public:
//     string addBinary(string a, string b) {
//         string result;

//         bool carry = false;
//         bool aBit, bBit, cBit;
//         int i, j;
//         for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
//             aBit = charToLogic(a[i]);
//             bBit = charToLogic(b[j]);
//             cBit = myXor(aBit, myXor(bBit, carry));
//             carry = (aBit && bBit) || (aBit && carry) || (bBit && carry);

//             result.insert(result.begin(), 1, logicToChar(cBit));
//         }
//         if (i >= 0) {
//             onePlus(a, i, result, carry);
//         }
//         else if (j >= 0) {
//             onePlus(b, j, result, carry);
//         }
//         else {
//             if (carry) {
//                 result.insert(result.begin(), 1, '1');
//             }
//         }
//         return result;
//     }
// };

class Solution {    //Can't pass, because can't deal with too large number
private:
    inline int strToIntBi(string s) {
        int result = 0;
        for (int i = s.size()-1, ri = 0; i >= 0; i--, ri++) {
            result += ((int)(s[i]-'0') << ri);
        }
        return result;
    }
    inline string intToStrBi(int d) {
        int highestBit;
        string result;
        char c;
        for (int i = 30; i >= 0; i--) {
            if (d >> i == 1) {
                highestBit = i;
            }
        }
        for (int i = highestBit; i >=0; i--) {
            if ((d >> i & 1) == 1) {
                result.push_back('1');
            }
            else {
                result.push_back('0');
            }
        }
        if (result.empty()) {
            return string("0");
        }
        else {}
        return result;
    }
public:
    string addBinary(string a, string b) {
        char cc[32];
        int ia = strToIntBi(a);
        int ib = strToIntBi(b);
        //cout << "ia:" << ia << " ib:" << ib << endl;
        int ic = ia + ib;
        return intToStrBi(ic);
    }
};
