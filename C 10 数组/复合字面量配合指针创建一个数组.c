# include "stdio.h"

# define SIZE 3


int main(){
    int * pt;
    pt = (int [3]) {1, 2, 3};   // 复合字面量使用指针指向, 以免被内存回收

    for (int i=0; i<SIZE; i++)
        printf("%-4d", *(pt+i));

    putchar('\n');

    return 0;
}