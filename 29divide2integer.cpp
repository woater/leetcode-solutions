#include <iostream>

using namespace std;


/*
**前提条件：除数不为0
**
**基本思路：利用减法，将被除数减到0，计数即可
**
**问题1：当处暑与被除数异号时，不能减计数
**solution: 分别处理同号异号情况
**问题2：可能结果溢出：当-2^31除-1时
**solution: 在函数开始时判断
**问题3：结果为整数或负数时取整方式不同
**solution: 与同号异号同时解决，采用不同计数方式
**问题4：当除数绝对值远远小于被除数时，循环会遍历很多很多次
**solution: 使用移位运算快速计算
*子问题：负数无法进行左移，因为是逻辑左移
*/


#define myAbs(x) ((x)>0?(x):(-(x)))
class Solution {
public:
    int divideBothPosi(int& dividend, int& divisor) {
        if (divisor > dividend) return 0; else;
        if (divisor == dividend) return 1; else;

        int testBits = divisor;
        int bitCnt = 0;
        int shiftBond = 0x3fffffff;
        while (testBits < dividend && testBits < shiftBond) {
            //cout << "while" << endl;
            //cout << testBits << endl;
            testBits = testBits << 1;
            ++bitCnt;
        }
        if (testBits )//
        bitCnt -= 1;
        int ans = 0;
        int rest = 0;
        for (int i = bitCnt; i >= 0 && dividend > 0; i--) {
            //cout << "for loop" << endl;
            //cout << i << " : " << bitCnt << endl;
            
            while (rest >= 0) {
                rest = dividend - (divisor << i);
                if (rest >= 0) {
                    dividend = rest;
                    ans += (1 << i);
                } else;
            }
            if (rest < 0) {
                rest = dividend;
            }
        }
        return ans;
    }
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0; 
        else if (dividend == 0x80000000 && divisor == -1) return 0x7fffffff; else;

        if (divisor == 1) return dividend;   // 不解决问题
        else if (divisor == -1) return -dividend;

        int ans = 0;
        if ( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ) { // same sign
            if (dividend < 0) {
                dividend = -dividend;
                divisor = -divisor;
            } else;
            
            return divideBothPosi(dividend, divisor);
        }
        else {
            dividend = myAbs(dividend);
            divisor = myAbs(divisor);
            int preAns = divideBothPosi(dividend, divisor);
            // if (dividend != 0)
            //     preAns -= 1; else;
            ans = -preAns;
        }
        return ans;
    }
};

int main(void)
{
    int a = 2147483647;
    int b = 2;
    cout << Solution().divideBothPosi(a, b) << endl;
    return 0;
}