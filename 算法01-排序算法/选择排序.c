# include "stdio.h"

# define LEN 10

/*  
    选择排序
    第一次从待排序的数据元素中选出最小(最大)的一个元素, 存放在序列的起始位置, 
    然后再从剩余的未排序元素中寻找到最小(最大)元素, 然后放到已排序的序列的末尾. 
    以此类推, 直到全部待排序的数据元素的个数为零.

    选择排序的主要优点与数据移动有关.
    如果某个元素位于正确的最终位置上, 则它不会被移动.
    选择排序每次交换一对元素, 它们当中至少有一个将被移到其最终位置上, 因此对n个元素的表进行排序总共进行至多(n-1)次交换.
    在所有的完全依靠交换去移动元素的排序方法中, 选择排序属于非常好的一种.

    平均时间复杂度	O(n²)
    最坏时间复杂度	O(n²)
    最优时间复杂度	O(n²)
    空间复杂度	总共O(n), 需要辅助空间O(1)
    最佳解	偶尔出现

    伪代码
        函数 选择排序 输入 ( 一个数组名称为array 其长度为length )
            m 从 0 到 length - 1
                min_i = m   // 当前m为其后所有元素最小值的下标
                n 从 m+1 到 length
                    如果 当前最小值array[min_i] > array[n]   // 向后找到了比min_i还要小的, 记录其下标, 
                        min_i = n
                    如果结束
                n 的循环结束
                如果 min_i != m
                    交换array[m]与array[min_i]的值
                如果结束
            m 的循环结束
        函数结束
*/

void selection_sort(int *, size_t);
void selection_sort2(int *, size_t);


int main(){

    int array[LEN] = {32, 45, 12, 65, 76, 23, 55, 87, 93, 10};

    selection_sort2(array, LEN);

    for (int i=0; i<LEN; i++)
        printf("%4d", array[i]);
    putchar('\n');

    return 0;
}


// 选择排序
void selection_sort(int array[], size_t len){
    int temp;
    size_t min_i;

    for (int m=0; m<len-1; m++) {
        min_i = m;   // 记录m之后最小值的下标, 初始化为当前要处理的位置m
        for (int n=m+1; n<len; n++) {
            if (array[min_i] > array[n])   // 向后找到了比min_i还要小的, 记录其下标
                min_i = n;
        }
        if (min_i != m) {
            temp = array[m];
            array[m] = array[min_i];
            array[min_i] = temp;
        }
    }
}


// 选择排序2, 按照以小到大排列int数组
void selection_sort(int array[], size_t len){
    int temp;

    for (int m=0; m<len-1; m++){
        for (int n=m+1; n<len; n++){
            if (array[m] > array[n]){   // 将当前位置用在其后的最小元素替换
                temp = array[n];
                array[n] = array[m];
                array[m] = temp;
            }
        }
    }
}