# include "stdio.h"


int main(){

    ;   // 空语句, 最简单的语句

    int num = 0;   // 声明语句

    printf("没有完成副作用的自增后缀的num: %d\n", num++);

    printf("完成副作用后的自增后缀的num: %d\n", num);

    return 0;
}