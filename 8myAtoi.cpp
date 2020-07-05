#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        //cout << INT_MAX << endl;
        int sign = 1;   //positive 1, negative -1
        int beginning = 0;  //record numbers beginning position
        while (str[beginning] == ' ') { //delete pre blank
            beginning++;
        }

        if (str[beginning] == '-') {   //negetive
            sign = -1;
            beginning++;
        }
        else if (str[beginning] == '+') {   //positive
            beginning++;
        }
        else if (str[beginning] < '0' || str[beginning] > '9'){ //invalid
            //cout << "quit0:" << str[beginning] << endl;
            return 0;
        }
        else {} // do nonthing

        int countBits = 0;  //number of bits of number chain
        int posi = beginning;

        while (str[posi] >= '0' && str[posi] <= '9') {
            posi++;
            countBits++;
        }

        posi = beginning;
        while (str[posi] == '0') {  //delete pre 0s
            posi++;
            countBits--;
            beginning++;
        }
        //cout << "countbits:" << countBits << endl;

        int Mod = 1;    //weight of each bit
        int result = 0;
        int tempNumb;   //temperate number

        for (int i = beginning + countBits - 1; i >= beginning; i--, Mod*=10) {
            //cout << "mod:" << Mod << endl;
            
            switch (str[i])
            {
            case '0':
                tempNumb = 0;
                break;
            case '1':
                tempNumb = 1;
                break;
            case '2':
                tempNumb = 2;
                break;
            case '3':
                tempNumb = 3;
                break;
            case '4':
                tempNumb = 4;
                break;
            case '5':
                tempNumb = 5;
                break;
            case '6':
                tempNumb = 6;
                break;
            case '7':
                tempNumb = 7;
                break;
            case '8':
                tempNumb = 8;
                break;
            case '9':
                tempNumb = 9;
                break;
            default:
                break;
            }
            //cout << "numb:" << tempNumb << endl;

            // detect if overflow 
            int adder = tempNumb * sign * Mod;
            if (sign > 0 && result > (INT_MAX - adder)) {
                return INT_MAX;
            }
            else if (sign < 0 && result < (INT_MIN - adder)) {
                return INT_MIN;
            }
            else {
                result += (tempNumb * sign * Mod);
            }
            //cout << "result:" << result << endl;
            if (result > 0 && sign < 0) {
                //cout << "min" << endl;
                //cout << "overflow" << endl;
                return INT_MIN;
            }
            else if (result < 0 && sign > 0) {
                //cout << "max" << endl;
                //cout << "overflow" << endl;
                return INT_MAX;
            }
            else {} // do nothing

            //即将溢出，进行处理
            if (Mod >= 100000000) {
                Mod *= 10;
                i--;
                if (i >= beginning)
                    //printf("%d",str[i] > '2');
                if (i >= beginning && str[i] > '2') {
                    //cout << "???" << endl;
                    return sign > 0 ? INT_MAX : INT_MIN;
                }
                else if (i >= beginning && str[i] == '1') {
                    result += (sign > 0 ? Mod : (-Mod));
                    i--;
                }
                else if (i >= beginning && str[i] == '2') {
                    if (sign > 0 && result > (INT_MAX - 2000000000)) {
                        return INT_MAX;
                    }
                    else if (sign < 0 && result < (INT_MIN + 2000000000)) {
                        return INT_MIN;
                    }
                    else {   
                        result += (sign > 0 ? 2000000000 : (-2000000000));
                        i--;
                        while (i >= beginning) {
                            if (str[i] != '0') {
                                return sign > 0 ? INT_MAX : INT_MIN;
                            }
                            else {}
                        }
                    }
                }
                else {}

                while (i >= beginning) {
                    //cout << "step:" << beginning - i << endl;
                    if (str[i--] != '0') {
                        //cout << "str[i] != 0" << endl;
                        //cout << "mod out" << endl;
                        return sign > 0 ? INT_MAX : INT_MIN;
                    }
                }
                return result;
            }
            else {}
        }
        //cout << "result" << result << endl;
        return result;

    }
};


