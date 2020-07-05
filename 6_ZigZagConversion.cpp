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