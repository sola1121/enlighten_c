# include "stdio.h"


/*
    二分查找(Binary Search)也称折半查找, 对数搜索算法, 它是一种在有序数组中查找某一特定元素的搜索算法.

    首先, 假设表中元素是按升序排列.
    搜索过程从数组的中间元素开始, 
        如果中间元素正好是要查找的元素, 则搜索过程结束;
        如果某一特定元素大于(或小于)中间元素, 则在数组大于(或小于)中间元素的那一半中查找, 而且跟开始一样从中间元素开始比较.
    重复以上过程, 直到找到找到匹配的元素, 使查找成功, 或直到子表不存在为止, 此时查找不成功.
    这种搜索算法每一次比较都使搜索范围缩小一半.

    注意, 对于要搜索的对象
        必须采用顺序存储结构
        必须按关键字大小有序排列

    平均时间复杂度	O(log₂ n)
    最坏时间复杂度	O(log₂ n)
    最优时间复杂度	O(1)
    空间复杂度	迭代：O(1) 递归：O(log₂ n) (无尾调用消除)
    最佳解	有

    伪代码
        BinarySearch(max,min,des)
            mid-<(max+min)/2
            while(min<=max)
                mid=(min+max)/2
                if mid=des then
                    return mid
                elseif mid >des then
                    max=mid-1
                else
                    min=mid+1
                return max
*/

# define LEN 10


int binary_search(int [], size_t, int);
int binary_search2(int [], size_t, int);


int main(){
    int array[LEN] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10};   // 所要查找的有序数组
    for (int i=0; i<LEN; i++)
        printf("%4d", array[i]);
    putchar('\n');

    const int value = 5;
    int ret = binary_search2(array, LEN, value);
    printf("\n查询值 %d, 在数组中的位置 %d\n", value, ret);

    return 0;
}


// 二分查找, 查找升序排列的数组
int binary_search(int array[], size_t len, int value){
    int mid;   // 记录当前查找的中间位置
    int left, right;   // 记录当前查找的左界限与右界限

    left = 0;   // 起始为数组头元素
    right = len - 1;   // 起始为数组尾元素

    while (left<=right){
        mid = left + (right - left) / 2;   // NOTE: 直接平均可能会溢位，所以用此算法
        if (array[mid] == value)   // 此时中间值正好是查找值
            return mid;
        else if (array[mid] < value)   // 此时中间值小于查找值, left向右取大
            left = mid;
        else if (array[mid] > value)   // 此时中间值大于查找值, right向左取小
            right = mid;
    }

    return -1;
}


// 二分查找, 查找升序排列并有重复元素的数组, 返回第一个符合元素的位置
int binary_search2(int array[], size_t len, int value){
    int mid;
    int left, right;

    left = 0;
    right = len - 1;

    while (left<=right){
        mid = left + (right - left) / 2;
        if (array[mid] == value) {
            for (; array[mid-1]==value&&mid>=0; mid--)   // 从当前找到的元素, 向前看是否是重复值, 返回前面的
                continue;
            return mid+1;
        } else if (array[mid] < value)
            left = mid;
        else if (array[mid] > value)
            right = mid;
    }

    return -1;
}