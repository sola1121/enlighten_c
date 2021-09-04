# include "stdio.h"


// 打印对因位置的斐波那契数
unsigned long long fibonacci(unsigned int index){
    int ret = 0;

    if (index>2)
        ret = fibonacci(index-1) + fibonacci(index-2);
    else
        return 1;
    
    return ret;
}


int main(){

    for (int i=1; i<=10; i++)
        printf("%llu   ", fibonacci(i));
    
    putchar('\n');

    return 0;
}