#include <string>
#include <iostream>
#include <vector>

using namespace std;
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
            printf("prefixFunc[%d]:%d\n", q, k-1);
            prefixFunc[q] = k;
        }
    }
public:
    void strStr(string txt, string pattern) {
        int sizeOfPat = pattern.size();
        int sizeOfT = txt.size();
        //声明并计算前缀函数
        int prefixFunc[sizeOfPat]; //包含m个状态，即匹配前n个字符的n个状态

        computePrefixFunc(pattern, prefixFunc);
        cout << endl << "PF:";
        for (int i = 0; i < sizeOfPat; i++) {
            cout << "[" << prefixFunc[i] << "]";
        }
        cout << endl;
        //对文本顺序检查

        int q = -1;
        for (int i = 0; i < sizeOfT; i++) {
            while (q >= 0 && pattern[q+1] != txt[i]) {  //后续匹配失败，进行转移
                cout << "w2." << q ;
                q = prefixFunc[q];
            }
            cout <<"q:" << q <<  " i:" << i << endl;
            if (pattern[q+1] == txt[i] ) {  //后续匹配成功，状态前进
                q += 1;
            }
            else {}
            if (q == sizeOfPat-1) {   //匹配完成
                cout << "End--q:" << q << endl;
                cout << "Pattern occurs whit shift:" << i-sizeOfPat+1 << endl;
                return;
                //q = prefixFunc[i];
            }
            else {}
        }
    }
};

int main()
{
    //string txt = "Finite Automata Algorithm: Finite Automata";
    string txt = "mississippi";
    string pat = "issip";
    //string pat = "Auto";
    Solution().strStr(txt, pat);
    system("pause");
    return 0;
}