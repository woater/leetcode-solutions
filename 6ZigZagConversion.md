#### 6.ZigZag Conversion

```txt
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
通过次数109,301提交次数231,465

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

{1}可以找到每一行对应元素之间的相对位置关系。

```c++
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    //计算对应行数的首行间距
    inline int countBasicMod(int index){
        return index == 1 ? 1 : ((index * 2) - 2);
    }
    //计算对应距离
    int countDest(int numRows, int rowIndex, bool& first) {
        //若是相对Z左侧
        if (first) {
            //第一行或最后一行
            if (rowIndex == 1 || rowIndex == numRows) {
                first = true;
                return countBasicMod(numRows);
            }
            else {
                first = false;
                return countBasicMod(numRows - rowIndex + 1); //Simplifiable
            }
        }
        else {
            first = true;
            return countBasicMod(rowIndex);
        }
    }
public:
    string convert(string const s, int const numRows) {

        string result = s;

        int strSize = s.size();

        int i = 0, j;
        int rowIndex = 1;
        //逐行进行计算
        while (rowIndex <= numRows) {
            j = rowIndex - 1;
            bool first = true;
            while (j < strSize && i < strSize) {
                //cout << "j|i|rowIndex|" << j << "|" << i << "|" << rowIndex << "|" << s[j] << first << endl;
                result[i++] = s[j];
                j += countDest(numRows, rowIndex, first);
            }
            rowIndex++;
        }
        return result;
    }
};
```

