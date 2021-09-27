# include "stdio.h"

# define SIZE 6


int sum_array(const int [], size_t);


int main(){

    int array[SIZE] = {1, 2, 3, 4, 5 ,6};

    printf("计算得出数组内元素和: %d\n", sum_array(array, SIZE));

    return 0;
}


// 使用const修饰的int指针, 在调用时声明并初始化为一个具有常属性的指针, 保证不可更改其指向地址的原数据
int sum_array(const int *array, size_t len){
    int ret = 0;

    for (int i=0; i<len; i++)
        ret += array[i];
    
    // array[3] = 22;   // 尝试更改指向地址的数据, 编译错误

    // 但是可以指向其他地址, 也就是说, 指针变量的值可以修改, 但是所指向的地址的原变量数据不能修改
    array = NULL;

    return ret;
}