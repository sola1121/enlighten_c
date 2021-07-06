/*
* 作者：LeetCode-Solution
* 链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer/solution/shu-zu-xing-shi-de-zheng-shu-jia-fa-by-l-jljp/
* 来源：力扣（LeetCode）
*/


# include "stdio.h"


// 逐位相交
/*
计算 123+912，我们从低位到高位依次计算 3+2、2+1 和 1+9。
任何时候，若加法的结果大于等于 10，把进位的 1 加入到下一位的计算中，所以最终结果为 1035。
*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int* res = malloc(sizeof(int) * fmax(10, numSize + 1));
    *returnSize = 0;
    for (int i = numSize - 1; i >= 0; --i) {
        int sum = num[i] + k % 10;
        k /= 10;
        if (sum >= 10) {
            k++;
            sum -= 10;
        }
        res[(*returnSize)++] = sum;
    }
    for (; k > 0; k /= 10) {
        res[(*returnSize)++] = k % 10;
    }
    for (int i = 0; i < (*returnSize) / 2; i++) {
        int tmp = res[i];
        res[i] = res[(*returnSize) - 1 - i];
        res[(*returnSize) - 1 - i] = tmp;
    }
    return res;
}


// 将整个加数 k 加入数组表示的数的最低位
/*
例子 123+912，我们把它表示成 [1,2,3+912]。
然后，我们计算 3+912=915。5 留在当前这一位，将 910/10=91 以进位的形式加入下一位。

然后，我们再重复这个过程，计算 [1,2+91,5]。
我们得到 9393，33 留在当前位，将 90/10=9 以进位的形式加入下一位。
继而又得到 [1+9,3,5]，

重复这个过程之后，最终得到结果 [1,0,3,5]。
*/
int* addToArrayForm2(int* num, int numSize, int k, int* returnSize) {
    int* res = malloc(sizeof(int) * fmax(10, numSize + 1));
    *returnSize = 0;
    for (int i = numSize - 1; i >= 0 || k > 0; --i, k /= 10) {
        if (i >= 0) {
            k += num[i];
        }
        res[(*returnSize)++] = k % 10;
    }

    for (int i = 0; i < (*returnSize) / 2; i++) {
        int tmp = res[i];
        res[i] = res[(*returnSize) - 1 - i];
        res[(*returnSize) - 1 - i] = tmp;
    }
    return res;
}


