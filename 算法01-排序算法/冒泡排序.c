# include "stdio.h"

# define LEN 10

/*
    冒泡排序
    比较相邻的元素. 如果第一个与第二个不满足想要的大小关系, 就交换他们两个.
    对每一对相邻元素作同样的工作, 从开始第一对到结尾的最后一对. 这步做完后, 最后的元素会是最大的数.
    针对所有的元素重复以上的步骤, 除了最后一个.
    持续每次对越来越少的元素重复上面的步骤, 直到没有任何一对数字需要比较.

    平均时间复杂度	О(n²)
    最坏时间复杂度	О(n²)
    最优时间复杂度	O(n)
    空间复杂度	总共 O(n), 需要辅助空间 O(1)
    最佳解	无

    伪代码
        函数 冒泡排序 输入 ( 一个数组名称为array 其长度为length )
            i 从 0 到 (length - 1) 
                j 从 0 到 (length - 1 - i) 
                    如果 array[j] > array[j + 1] 
                        交换 array[j] 和 array[j + 1] 的值 
                    如果结束 
                j循环结束 
            i循环结束 
        函数结束

    助记码
        i∈[0,N-1)               //循环N-1遍
            j∈[0,N-1-i)           //每遍循环要处理的无序部分
                swap(j,j+1)         //两两排序（升序/降序）
*/


void bubble_sort(int *, size_t);


int main(){

    int array[LEN] = {32, 45, 12, 65, 76, 23, 55, 87, 93, 10};

    bubble_sort(array, LEN);

    for (int i=0; i<LEN; i++)
        printf("%4d", array[i]);
    putchar('\n');

    return 0;
}


// 冒泡排序, 按照以小到大排列int数组
void bubble_sort(int array[], size_t len){
    int temp;

    for (int m=0; m<len-1; m++){
        for (int n=0; n<len-m-1; n++){
            if (array[n] > array[n+1]){   // 比较相邻两个元素, 如果前面的数大于后面的, 就交换两者位置
                temp = array[n];
                array[n] = array[n+1];
                array[n+1] = temp;
            }
        }
    }
}
