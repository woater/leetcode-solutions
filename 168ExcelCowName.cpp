#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int quotient, reserv;
        string result;
        while (n > 0) {
            if (n % 26 == 0) {
                n = (n / 26) - 1;
                result.insert(result.begin(), 'Z');
            }
            else {
                quotient = n / 26;
                reserv = n - (quotient * 26);
                n = quotient;
                result.insert(result.begin(), 'A' - 1 + reserv);
            }
        }
        return result;
    }
};