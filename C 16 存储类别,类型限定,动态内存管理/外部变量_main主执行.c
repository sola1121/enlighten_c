# include "stdio.h"

/*
    使用 外部变量_数据部分.c 中的外部变量
*/

extern int len;

extern int ex_array[];


int main(){

    extern int len;   // 如果有在该文件函数外面引用声明, 可以省略

    extern int ex_array[];   // 如果有在该文件函数外面引用声明, 可以省略


    for (int i=0; i<len; i++)
        printf("%d   ", ex_array[i]);

    putchar('\n');
    return 0;
}