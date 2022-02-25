# include "stdio.h"
# include "stdlib.h"


void fun1(){
    puts("fun1被调用.");
}


void fun2(){
    puts("fun2被调用.");
}


int main(){

    // 向exit()退出前执行函数列表中注册函数, 将会以注册顺序的倒序执行
    atexit(fun1);
    atexit(fun2);

    puts("程序将退出.");

    exit(0);   // 等价于  return 0;
}
