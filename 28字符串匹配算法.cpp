#include <string>
#include <vector>
#include <iostream>

#define min(x,y) (((x)<(y))?(x):(y))
#define RANGE_OF_CHAR 0xff

using namespace std;

class Solution {
private:
    int countNextState(string& pattern, int m, int state, char c) {
        
        if (state < m && c == pattern[state]) {
            return state + 1;
        }
        
        int i;
        for (int ns = state; ns > 0; ns--) { //ns is next state
            if (pattern[ns-1] == c) {
                for (i = 0; i < ns-1; i++) {
                    if (pattern[i] != pattern[state-ns+1+i]) {
                        break;
                    }
                    else {}
                }
                if (i == (ns - 1)) {
                    return ns;
                }
            }
        }
        return 0;
    }
    void computeTransitionFunc(string pattern, int TF[][RANGE_OF_CHAR]) {
        int m = pattern.size();
        for (int q = 0; q <= m; q++) {
            for (int c = 0; c < RANGE_OF_CHAR; c++) {
                TF[q][c] = countNextState(pattern, m, q, c);
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            
        cout << "line45" << endl;
            return 0;
        }
        else if(haystack.size() == 0) {
            
        cout << "line50" << endl;
            return -1;
        }
        else {
            int sizeOfNeedle = needle.size();
            int sizeOfHaystack = haystack.size();
            if (sizeOfHaystack < sizeOfNeedle) {
                
            cout << "line58" << endl;
                return -1;
            }
            else {
                int TF[sizeOfNeedle+1][RANGE_OF_CHAR];

                computeTransitionFunc(needle, TF);

                int state = 0;
                for (int i = 0; i < sizeOfHaystack; i++) {
                    state = TF[state][haystack[i]];
                    cout << state << endl;
                    if (state == sizeOfNeedle) {
                        cout << "line70" << endl;
                        return i - sizeOfNeedle + 1;
                    }
                }
            }
        }
        cout << "line76" << endl;
        return -1;
    }
};

int main()
{
    //string txt = "Finite Automata Algorithm: Finite Automata";
    string txt = "mississippi";
    string pat = "issip";
    //string pat = "Auto";
    cout << "at:" << Solution().strStr(txt, pat) << endl;
    system("pause");
    return 0;
}