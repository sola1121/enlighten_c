# include "stdio.h"


int main(){

    printf("创建长度为 %lu 的数组\n", sizeof(int));

    int array[sizeof(int)] = {1, 22, 333, 4444};   // sizeof的运算结果是一个数, 算作常量

    for (int i=0; i<sizeof(int); i++)
        printf("%-6d", array[i]);

    putchar('\n');
    return 0;
}