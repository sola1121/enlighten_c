# include "stdio.h"

/*
    变长数组 variable length array 就是可以使用变量定义长度的数组
    一般使用变量定义长度首先考虑到的是使用malloc或者calloc定义对应类型指针的方式
    但在C99标准后, 可以使用变量直接定义数组长度, 当然, 声明了的数组长度还是不能改变的, 因为内存已经分配好了
    但得使用C++ 的编译器, 如 g++
*/


int main(){

    int len = 10;

    int array[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i=10; i<len; i++) {
        printf("%4d", array[i]);
    }
    putchar('\n');

    return 0;
}