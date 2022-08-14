# include "stdio.h"

# define LEN 10

/*
    插入排序
    是一种简单直观的排序算法.
    就像打扑克牌, 每次从牌堆中抽一张牌, 然后按一定顺序放入手牌, 然后插入位置后面的牌向后挪一位

    从第一个元素开始, 该元素可以认为已经被排序
    取出下一个元素, 在已经排序的元素序列中从后向前扫描
    如果该元素(已排序)大于新元素，将该元素移到下一位置
    重复上一个步骤, 直到找到已排序的元素小于或者等于新元素的位置
    将新元素插入到该位置后, 重复上面步骤, 直到完成

    平均时间复杂度 O(n²)
    最坏时间复杂度 O(n²)
    最优时间复杂度 O(n)
    空间复杂度 O(n), 需要辅助空间 O(1)
    最佳解 无


    伪代码
        函数 插入排序 输入 ( 一个数组名称为array 其长度为length)
            i 从 1 到 length
                key = array[i]   // 取出待插入元素
                j = i-1   // 当前排序最末尾元素位置j

                // 从后向前, 直到到表头与当前j位置元素比取出待插入元素大, 该j位置及其后元素向后移一位, 插入
                循环 满足 j>=0 and array[j] > key 执行
                    array[j+1] = array[j]
                    j --
                j循环结束
                array[j+1] = key
            i循环结束
        函数结束
*/

void insertion_sort(int *, size_t);


int main(){

    int array[LEN] = {32, 45, 12, 65, 76, 23, 55, 87, 93, 10};

    insertion_sort(array, LEN);

    for (int i=0; i<LEN; i++)
        printf("%4d", array[i]);
    putchar('\n');

    return 0;
}


// 插入排序, 按照以小到大排列int数组
void insertion_sort(int array[], size_t len){
    int key;
    int m, n;   // m是从未排序的堆中拿出的元素下标, n是已排序的序列的最后一个元素下标

    for (m=1; m<len; m++){
        key = array[m];   // 从未处理中取出待处理元素
        n = m - 1;   // 找到当前已排序的表尾
        while ((n>=0) && (array[n]>key)){   // 因为是从后向前遍历, 所以当后面的array[n] 大于 当前key, 就将其插入key的后面
            array[n+1] = array[n];   // 元素后移一位
            n--;
        }
        array[n+1] = key;   // 腾出来的空位置插入元素
    }
}
