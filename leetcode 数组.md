### 4.寻找两个有序数组的中位数

#### 解题思路

1. 首先考虑有数组为空的情况，直接取非空数组的中位数即可，在数组大小为奇数时，用链表大小整除2向下取整正好得到中位数；当链表大小为偶数时，链表大小整除2得到的是中间靠后那个数的指数，需取两数平均数。

2. 当两个数组都不空时，分两种情况讨论：

   1. 两个数组不相交

      此时情况较为简单，

   2. 两个数组相交

```c

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // 情况1开始
    if (nums1Size == 0) {
        if ( (nums2Size % 2) == 0) {
            return ((nums2[nums2Size/2] + nums2[nums2Size/2 - 1]) / 2.0);
        }
        else {
            return (double)nums2[nums2Size/2]
        }
    }
    else if (nums2Size == 0) {
        if ( (nums1Size % 2) == 0) {
            return ((nums1[nums1Size/2] + nums1[nums1Size/2 - 1]) / 2.0);
        }
        else {
            return (double)nums1[nums1Size/2]
        }
    }
    // 情况1结束
    // 情况2开始
    else {
        // 当nums1小于nums2且不相交时
        if (nums1[nums1Size-1] < nums2[0]) {
            int index;
            int differ = nums1Size - nums2Size;
            // 当中位数位于较小的1数组中时
            if (differ >= 0) {
                index = nums1Size - ((nums1Size - nums2Size)/2) - 1;
                if (differ % 2) {
                return (double)nums1[index];
                }
                else {
                    return (nums1[index] + nums1[index - 1]) / 2.0;
                }
            }
            else {
                index = (nums2Size-nums1Size)/2;
                return (double)nums2[index];
            }
        }
        // // 当nums2小于nums1且不相交时， 与上个小情况对称
        else if (nums2[nums2Size-1] < nums1[0]) {}
        else if
    }
}
```

