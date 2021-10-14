# include "stdio.h"

# define LEN 10

/*  
    选择排序
    第一次从待排序的数据元素中选出最小(或最大)的一个元素, 存放在序列的起始位置, 
    然后再从剩余的未排序元素中寻找到最小(大)元素, 然后放到已排序的序列的末尾. 
    以此类推, 直到全部待排序的数据元素的个数为零.

    选择排序的主要优点与数据移动有关.
    如果某个元素位于正确的最终位置上, 则它不会被移动.
    选择排序每次交换一对元素, 它们当中至少有一个将被移到其最终位置上, 因此对n个元素的表进行排序总共进行至多(n-1)次交换.
    在所有的完全依靠交换去移动元素的排序方法中, 选择排序属于非常好的一种.

    平均时间复杂度	О(n²)
    最坏时间复杂度	О(n²)
    最优时间复杂度	О(n²)
    空间复杂度	总共О(n), 需要辅助空间O(1)
    最佳解	偶尔出现
*/

void selection_sort(int *, size_t);


int main(){

    int array[LEN] = {32, 45, 12, 65, 76, 23, 55, 87, 93, 10};

    selection_sort(array, LEN);

    for (int i=0; i<LEN; i++)
        printf("%4d", array[i]);
    putchar('\n');

    return 0;
}


// 选择排序, 按照以小到达排列int数组
void selection_sort(int array[], size_t len){
    int temp;

    for (int m=0; m<len-1; m++){
        for (int n=m+1; n<len; n++){
            if (array[m] > array[n]){   // 选择最小的元素, 如果前面的数大于后面的, 就交换位置
                temp = array[m];
                array[m] = array[n];
                array[n] = temp;
            }
        }
    }
}