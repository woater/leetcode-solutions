#include <string>
#include <iostream>


using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        char lastC;     //recorf last char
        int countCounti;    //count repeat times
        for(int i = 2; i <= n; i++) {
            string support;     //construct next string
            lastC = '0';        //set to be NULL
            countCounti = 0;    //set to be 0

            for(int j = 0; j < result.size(); j++) {    //iterate each char of last string
                if (lastC == result[j]) {
                    countCounti++;
                    //cout << countCounti << endl;
                }
                else {
                    if(lastC != '0') {  //except first one
                    support.push_back('0' + countCounti);
                    support.push_back(lastC);
                    //cout << "change:" <<  support << endl;
                    }
                    else {}
                    lastC = result[j];
                    countCounti = 1;
                }
            }
            //cout << "count:" << countCounti << " lastC:" << lastC << endl;
            //cout << "1st:" << support << endl;
            support.push_back('0' + countCounti);
            support.push_back(lastC);
            cout << i << ":" << support << endl;
            result = support;
        }
        return result;
    }
};