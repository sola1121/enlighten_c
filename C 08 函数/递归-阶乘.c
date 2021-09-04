# include "stdio.h"
# include "stdlib.h"
# include "ctype.h"


// 计算n的阶乘
unsigned long long factorial(int n){

    long long ret;

    if (n > 0)
        ret = n * factorial(n-1);
    else 
        ret = 1;
    
    return ret;
}


int main(){

    int input = 0;

    start:
    printf("输入在0-12之间的数, 以计算其阶乘\n");
    scanf("%d", &input);

    if (input = 'q' || input == 'Q')
        exit(0);

    if (input>12 || input<0)
        goto start;
    
    printf("\n所得结果为: %llu\n", factorial(input));

    return 0;
}