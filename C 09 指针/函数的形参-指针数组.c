# include "stdio.h"

# define SIZE 5


void put_arr(int *[], int);


int main(){

    int nums[SIZE] = {1, 2, 3, 4, 5};
    int *array[SIZE];
    
    for (int i=0; i<SIZE; i++)
        array[i] = nums+i;

    put_arr(array, SIZE);

    return 0;
}


// 遍历打印内容, 指针数组, 即一个数组保存的内容是指针
void put_arr(int *array[], int len){
    for (int i=0; i<len; i++)
        printf("%d   ", *array[i]);   // array[i]的值是地址, 使用解引用运算符*获得其所在地址的值
    
    putchar('\n');
}