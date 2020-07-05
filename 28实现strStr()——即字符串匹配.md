#### 28.实现strStr()——即字符串匹配

｛1｝朴素字符串匹配算法

在文本串的每个位置与模式串进行比较，算法复杂度为O((n-m+1)m)

```c++
class Solution {
private:
    bool matchSubstr(string haystack, string needle, int posi) {
        for (size_t charPosi = 0; charPosi < needle.size(); charPosi++) {
            if (haystack[posi + charPosi] != needle[charPosi]) {
                return false;
            }
            else {}
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        else if(haystack.size() == 0) {
            return -1;
        }
        else {
            int end = haystack.size() < needle.size() ? haystack.size() : (haystack.size()-needle.size()+1);
            for (int posi = 0; posi < end; posi++) {
                if (matchSubstr(haystack, needle, posi)) {
                    return posi;
                }
                else {}
            }
            return -1;
        }
    }
};
```

｛2｝Rabin-Karp算法——利用数论，留待之后学习

｛3｝有限状态机算法

关键是计算状态转移函数

计算状态转移函数：对每个状态和输入字符进行匹配，取最大（靠后）的状态

```c++
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
```

当pattern很长时，超出时间限制

｛3｝Knuth-Morris-Pratt, KMP算法

使用前缀函数计算偏移量

```c++
class Solution {
private:
    void computePrefixFunc(string pattern, int* prefixFunc) {

        int m = pattern.size();
        //等待位置即为-1
        prefixFunc[0] = -1;
        //k记录最大匹配位置
        int k = -1;
        //对前缀列表中每一位置逐一设置
        for (int q = 1; q < m; q++) {
            //匹配不成功，则进行转移
            while (k >= 0 && pattern[k + 1] != pattern[q]) {
                //printf("w1:k+1:%c_q:%c_preFuncOfK:%d\n", pattern[k+1], pattern[q], prefixFunc[k]);
                k = prefixFunc[k];
            }
            if (pattern[k+1] == pattern[q]) {
                k += 1;
            }
            //printf("prefixFunc[%d]:%d\n", q, k-1);
            prefixFunc[q] = k;
        }
    }
public:
    int strStr(string txt, string pattern) {
        int sizeOfPat = pattern.size();
        int sizeOfT = txt.size();
        if (sizeOfPat == 0) {
            return 0;
        }
        else if (sizeOfPat > sizeOfT || sizeOfT == 0) {
            return -1;
        }
        else {}
        //声明并计算前缀函数
        int prefixFunc[sizeOfPat]; //包含m个状态，即匹配前n个字符的n个状态

        computePrefixFunc(pattern, prefixFunc);
        //cout << endl << "PF:";
        for (int i = 0; i < sizeOfPat; i++) {
            //cout << "[" << prefixFunc[i] << "]";
        }
        //cout << endl;
        //对文本顺序检查

        int q = -1;
        for (int i = 0; i < sizeOfT; i++) {
            while (q >= 0 && pattern[q+1] != txt[i]) {  //后续匹配失败，进行转移
                //cout << "w2." << q ;
                q = prefixFunc[q];
            }
            //cout <<"q:" << q <<  " i:" << i << endl;
            if (pattern[q+1] == txt[i] ) {  //后续匹配成功，状态前进
                q += 1;
            }
            else {}
            if (q == sizeOfPat-1) {   //匹配完成
                //cout << "End--q:" << q << endl;
                //cout << "Pattern occurs whit shift:" << i-sizeOfPat+1 << endl;
                return i-sizeOfPat+1;
                //q = prefixFunc[i];
            }
            else {}
        }
        return -1;
    }
};
```



```txt
执行用时 :4 ms, 在所有 C++ 提交中击败了92.89%的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
```

