# include "stdio.h"
# include "stdarg.h"

# define PRLN(value, ...) printf("内容: " #value ",值: %d %s\n", value, __VA_ARGS__) 

// # if , # elif指令后跟整型常量表达式

int main(){
    # define NUM 1

    # if NUM == 1
        PRLN(NUM, "为真.");
    # elif NUM == 0
        puts("不为真.");
    # endif

    putchar('\n');

    # if defined NUM
        puts("已定义.");
    # else
        puts("未定义.");
    # endif

    putchar('\n');

    int num = 1;

    # if num == 1
        puts("可以使用指令检查C源码中的变量.");
    # else
        puts("不能使用指令检查C源码中的变量.");
    # endif

    return 0;
}