# include "stdio.h"

# define MSG "hello, world."

/*
    字符串字面量在程序运行时, 载入到静态存储区
    当使用对应字符串字面量对数组赋值的时候, 将会拷贝一份副本给数组作为存储
    当使用对应字符串字面量为指针赋值的时候, 指针直接指向其所在字符首地址, 即用地址赋值
*/


int main(){

    char array[] = MSG;
    char * pt = MSG;

    printf("原字符串: %s\n在静态内存中首字符的地址: %p\n", MSG, MSG);

    printf("数组array首字符地址: %p\n", array);             // MSG副本的地址
    printf("指针pt首字符地址: %p\n", pt);                   // 就是MSG的地址
    printf("同值字符串首字符地址: %p\n", "hello, world.");   // 就是MSG的地址

    return 0;
}