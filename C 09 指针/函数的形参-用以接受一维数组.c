# include "stdio.h"

# define SIZE 10


int sum_array1(int [], size_t);
int sum_array2(int *, size_t);


int main(){
    
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("计算得出数组内元素和: %d\n", sum_array1(array, SIZE));
    printf("计算得出数组内元素和: %d\n", sum_array2(array, SIZE));

    return 0;
}


// 数组表示法的指针形参, 空的[]只有在做形参时等价于*, 该函数在调用时会被实参赋值数组首地址
int sum_array1(int array[], size_t len){
    int ret = 0;

    for (int i=0; i<len; i++)
        ret += *(array+i);   // 使用指针表示法

    return ret;
}


// 指针表示法的指针形参, 该函数在调用时会被实参赋值数组首地址
int sum_array2(int * array, size_t len){
    int ret = 0;

    for (int i=0; i<len; i++)
        ret += array[i];   // 使用数组表示法

    return ret;
}

