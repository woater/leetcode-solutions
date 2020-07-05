#### 69square root

```txt
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
通过次数110,132提交次数292,585

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

｛1本来应该简单但是搞得很复杂的简单算法｝

```c++
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        else if (x > 0x7FFEA810) {
            return 46340;
        }
        int bond = x / 2 + 1;
        bond = x > 46340 ? 46340 : bond;
        int i;
        for (i = bond; i > 0; i--) {
            int result = i * i;
            //cout << i << endl;
            if (result == x) {
                cout << "1st" << endl;
                return i;
            }
            else if(result < x) {
                //cout << "2nd" << endl;
                return i;
            }
            else {}
        }
        //cout << "3rd" << endl;
        return i;
    }
};
```

｛2｝上述算法的二分查找版本。略

｛3｝袖珍计算器算法

```c++
#define e 2.71828
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = pow(e, 0.5 * log(x));
        int right = left + 1;
        return (long)right * right > x ? left : right;
    }
};
```

