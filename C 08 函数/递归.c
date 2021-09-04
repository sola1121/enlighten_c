# include "stdio.h"

# define FORMAT "爬楼梯, 到达楼层: %d, 所在内存地址 - %p\n"


void up_and_down(int n){
    printf(FORMAT, n, &n);
    if (n < 7)
        up_and_down(n+1);
    printf(FORMAT, n, &n);
}


int main(){

    up_and_down(1);
}