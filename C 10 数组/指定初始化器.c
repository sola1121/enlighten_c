# include "stdio.h"


/*
    可以对指定下标的数组数据进行初始化
*/


int main(){

    int array1[10] = {[5]=666, [7]=888},
        array2[10] = {[2]=333,444,555};

    puts("array1:");
    for (int i=0; i<10; i++)
        printf("%d  ", array1[i]);

    puts("\narray2:");
    for (int i=0; i<10; i++)
        printf("%d   ", array2[i]);

    putchar('\n');
    return 0;
}