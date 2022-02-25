# include "stdio.h"


// 内联函数, 内部链接, 文件作用域, 
inline static sum(int a, int b){
    return a+b;
}


int main(){
    int a = 3, b = 2;

    printf("%d\n", sum(a, b));

    return 0;
}