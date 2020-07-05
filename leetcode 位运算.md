1. C语言中，移位运算不直接改变原操作数的值；

#### [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

~~~ txt
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
~~~

~~~ c
int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++)//利用异或运算的自反性
        result ^= nums[i];
    return result;
}
~~~



### [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

~~~ txt
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

 

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
 

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。
~~~

~~~ c
int hammingWeight(uint32_t n) {
    int cnt = 0;
    unsigned n_binary = n;
    for (int i = 31; i>=0; i--) {
        if ( (n_binary & 1 ) == 1) { //若最后一位是1则计入cnt
            cnt++;
        }
        n_binary = n_binary >> 1; //一次检查各位
    }
    return cnt;
}
~~~

#### [268. 缺失数字](https://leetcode-cn.com/problems/missing-number/)

~~~ txt
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
~~~

~~~ c
int missingNumber(int* nums, int numsSize) {
    int total = ((numsSize+1)*numsSize)/2;//利用等差级数求和公式计算总和，减去数组中元素即为丢失元素
    for (int i =0; i<numsSize; i++)
        total = total -nums[i];
    return total;
}
~~~



### [461. 汉明距离](https://leetcode-cn.com/problems/hamming-distance/)

问题描述

~~~ txt
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.
~~~

代码

~~~ c 
int hammingDistance(int x, int y) {
    int i;
    //若为负数则变为原码（各位取反，末位加1）
    if (x < 0)
        x = ~x +1;
    if (y < 0)
        y = ~y +1;
    //确保为原码，此步可省略
    unsigned ux = x;
    unsigned uy = y;
    //汉明距离
    int dist = 0;
    //利用亦或找出不同的位
    int diff = ux ^ uy;
    //利用1左移和且运算来确定不同的位数
    unsigned one = 1;
    for (i=0; i < 31; i++) {
        dist += diff & one;
        xor = xor >> 1;
    }
    return dist;
}
~~~

### [476. 数字的补数](https://leetcode-cn.com/problems/number-complement/)

~~~ txt
给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

注意:

给定的整数保证在32位带符号整数的范围内。
你可以假定二进制数不包含前导零位。
示例 1:

输入: 5
输出: 2
解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
示例 2:

输入: 1
输出: 0
解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
~~~

~~~ c 
int findComplement(int num) {
    unsigned test0=num;
    int cnt=0;
    while( (test0 & 0x80000000) == 0) {
        cnt++;
        test0 = test0 << 1;
    }
    unsigned mask = 0xffffffff;
    mask = mask >> cnt;
    unsigned result = num;
    result = ~result;
    return result & mask;
}
~~~

### [693. 交替位二进制数](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/) 

~~~ txt
给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

示例 1:

输入: 5
输出: True
解释:
5的二进制数是: 101
示例 2:

输入: 7
输出: False
解释:
7的二进制数是: 111
示例 3:

输入: 11
输出: False
解释:
11的二进制数是: 1011
 示例 4:

输入: 10
输出: True
解释:
10的二进制数是: 1010
~~~

~~~ c
bool hasAlternatingBits(int n) {
    unsigned n_binary = n;//用无符号数表示，确保算术右移（对结果没有影响）
    const unsigned mask = 1;
    unsigned last = mask & n_binary;
    
    //确定前置0个数
    unsigned test0 = n_binary;
    int i = 31;
    int cnt_zero = 0;
    while ( ((test0 & 0x80000000) == 0) && i>0) {
        cnt_zero++;
        test0 = test0 << 1;
        i--;
    }
    //以7为例，有29个前置0 
    n_binary = n_binary >> 1;
    //i = 2
    //共计(31-前置0位数)次比较
    for (i = 31 - cnt_zero; i > 0; i--) {
        if (last == (n_binary & mask) )
            return false;
        else {
            last = n_binary & mask;
            n_binary = n_binary >> 1;
        }
    }
    return 1;
}
~~~

