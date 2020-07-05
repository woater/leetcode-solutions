# leetcode 动态规划刷题笔记

## Easy

### 53.最大（连续）子序列和

``` txt
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

#### O(n^2算法)

粗暴采用动态规划，把问题搞复杂了。

``` c	
int maxSubArrayOn2(int* nums, int numsSize) {		//o(n^2)
	int **sum = (int**)malloc(sizeof(int*)*numsSize);    //构造求和结果阵列
	for (int i = 0; i < numsSize; i++) {
		sum[i] = (int*)malloc(sizeof(int)*numsSize);
	}
	for (int i = 0; i < numsSize; i++) {                            //初始化单节点结果
sum[i][i] = nums[i];
	}
	int **best = (int**)malloc(sizeof(int*)*numsSize);    //构造求和结果阵列
	for (int i = 0; i < numsSize; i++) {
		best[i] = (int*)malloc(sizeof(int)*numsSize);
	}
	for (int l = 2; l <= numsSize; l++) {
		for (int i = 0; i < numsSize - l + 1; i++) {
			int j = i + l - 1;
			sum[i][j] = (int)0x80000000;
			for (int k = i; k <= j - 1; k++) {
				int q = sum[i][k] + sum[k + 1][j];
				if (q > sum[i][j]) {
					sum[i][j] = q;
					best[i][j] = k;
				}
			}
		}
	}
	int max = (int)0x80000000;
	for (int i = 0; i < numsSize; i++) {
		for (int j = 0; j < numsSize; j++) {
			if (sum[i][j] > max) {
				max = sum[i][j];
			}
			else {}
		}
	}
	return max;
}
```

#### O(n)算法

```c
int maxSubArrayOn(int* nums, int numsSize)	//O(n)
{
	int max = nums[0];
	int content = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (content < 0) {
			content = nums[i];
		}
		else {
			content += nums[i];
		}
		if (content > max) {
			max = content;
		}
		else {}
	}
	return max;
}
```

### 121.买卖股票的最佳时机

``` txt
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

#### O(n^2)算法

```c
int maxProfitOn2(int* prices, int pricesSize) //O(n^2)
{
	int maxProfit = 0;
	int profit;
	for (int i = 0; i < pricesSize; i++) {
		for (int j = i + 1; j < pricesSize; j++) {
			if ((profit = prices[j] - prices[i]) > 0) {
				if (profit > maxProfit) {
					maxProfit = profit;
				}
				else {}		//do nothing
			}
		}
	}
	return maxProfit;
}
```

#### O(n)算法

```c
int maxProfit(int* prices, int pricesSize)	//O(n)
{
	if (pricesSize <= 1) {
		return;
	}
	else {} // do nothing
	int maxProfit = 0;
	int minBought = prices[0];
	int profit;
	for (int i = 1; i < pricesSize; i++) {
		if ((profit = prices[i] - minBought) > 0) {
			if (profit > maxProfit) {
				maxProfit = profit;
			}
			else {}
		}
		else {						// prices[i] <= minBought
			minBought = prices[i];
		}
	}
}
```

### 70.爬楼梯

```txt
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

#### 问题分析：

观察 1， 2， 3， 4时得到：ways[n] = ways[n-1] + ways[n-2]；

可用O(n)算法完成

#### O(2<sup>n</sup>)算法

算法课用递归调用二叉树分析，树的高度为n，所以时间复杂度为O(2<sup>n</sup>)，空间复杂度相同；

得知该算法非常能搞事。

```c
int climbStairs2powN(int n) {	//2^n
	int ways;
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
	return ways;
}
```

#### O(n)算法

```c
int climbStairs(int n) {
	if (n <= 2) {
		return n;
	}
	else {}
	int *ways = (int*)malloc(sizeof(int)*n);
	ways[0] = 1;
	ways[1] = 2;
	for (int i = 2; i < n; i++) {
		ways[i] = ways[i - 1] + ways[i - 2];
	}
	return ways[n - 1];
}
```

### 198.打家劫舍

```txt
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

### 303.区域和检索 - 数组不可变

```txt
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

##### 超出时间限制

没有考虑到简单复用性，复杂程度与暴力算法相同

```c
typedef struct {
    int **matrix;
    int N;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {     
    NumArray *array = (NumArray*)malloc(sizeof(NumArray));
    array->matrix = (int**)malloc(sizeof(int*)*numsSize);
    array->N = numsSize;
    int **mat = array->matrix;
    for (int i = 0; i < numsSize; i++) {
        mat[i] = (int*)malloc(sizeof(int)*numsSize);
    }
    
    for (int i = 0; i < numsSize; i++) {
        mat[i][i] = nums[i];
    }
    for (int l = 2; l <= numsSize; l++) {	//超出时间限制
        for (int i = 0; i < numsSize - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                mat[i][j] = mat[i][k] + mat[k+1][j];
            }
        }
    }
    /* 同样超出时间限制
    for (int l = 2; l <= numsSize; l++) {
        for (int i = 0; i < numsSize - l + 1; i++) {
            int j = i + l - 1;
            mat[i][j] = mat[i][j - 1] + mat[j][j];
        }
    }
    */
    return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
  return obj->matrix[i][j];
}

void numArrayFree(NumArray* obj) {
    int n = obj->N;
    for (int i = 0; i < n; i++) {
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
```

##### O(n^2) 通过，效率最低

```c
typedef struct {
    int **matrix;
    int N;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {     
    NumArray *array = (NumArray*)malloc(sizeof(NumArray));
    array->matrix = (int**)malloc(sizeof(int*)*numsSize);
    array->N = numsSize;
    int **mat = array->matrix;
    for (int i = 0; i < numsSize; i++) {
        mat[i] = (int*)malloc(sizeof(int)*numsSize);
    }
    for (int i = 0; i < numsSize; i++) {
        mat[i][i] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            mat[i][j] = mat[i][j-1] + nums[j];
        }
    }
    /*
    for (int l = 2; l <= numsSize; l++) {
        for (int i = 0; i < numsSize - l + 1; i++) {
            int j = i + l - 1;
            mat[i][j] = mat[i][j - 1] + mat[j][j];
        }
    }
    */
    return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
  return obj->matrix[i][j];
}

void numArrayFree(NumArray* obj) {
    int n = obj->N;
    for (int i = 0; i < n; i++) {
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
```

