# include "stdio.h"

/*
    块中的静态变量, 具有块作用域, 无链接, 静态存储期
    即只在块中可见, 不可在不同翻译单元或者多个文件中使用, 在程序执行期间一直存在
*/


void number_put();

int main(){

    for (int i=0; i<10; i++)
        number_put();

    putchar('\n');
    return 0;
}


void number_put(){
    /*
        块作用域的静态变量, 在编译时初始化, 未指明值则为0. 
        会在执行期间一直存在, 但只在函数块中可见
    */
    static int num;
    printf("%d   ", num++);
}