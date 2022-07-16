# include "stdio.h"


# define LEN 10


// 递归实现的二分查找
int binary_search(const int array[], int left, int right, int value);



int main(){
    int array[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // 所要查找的有序数组
    for (int i=0; i<LEN; i++)
        printf("%4d", array[i]);
    putchar('\n');

    const int value = 1;
    int ret = binary_search(array, 0, LEN-1, value);
    printf("\n查询值 %d, 在数组中的位置 %d\n", value, ret);

    return 0;
}


// 二分查找, 对于升序排列的数组
int binary_search(const int array[], int left, int right, int value) {
	if (left > right)
		return -1;

	int mid = left + (right - left) / 2;    // NOTE: 直接平均可能會溢位，所以用此算法
	if (array[mid] > value)   // 中间元素大于查找值, right向左取小
		return binary_search(array, left, mid - 1, value);
	else if (array[mid] < value)   // 中间元素小于查找值, left向右取大
		return binary_search(array, mid + 1, right, value);
	else
	    return mid;        // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
}