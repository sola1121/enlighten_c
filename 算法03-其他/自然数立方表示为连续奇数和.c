#include <stdio.h>

/*
    任何一个自然数n的立方都可以表示为该n个连续奇数的和
*/


int main() {

    int num, cube, sum;
    int odd, i;
    
    puts("输入一个自然数: ");
    scanf("%d", &num);

    cube = num*num*num;

    for (odd=1; odd<cube; odd+=2) {
        sum = 0;
        for (i=odd; i<odd+2*num; i+=2) {   // 以odd作为开头的连续num个奇数的和
            sum += i;
        }
        if (sum==cube) {   // 当所得的和满足题设, 以odd作为开头向后输出连续的奇数
            for (i=odd; i<odd+2*num; i+=2) {
                printf("%d ", i);
            }
            putchar('\n');
        }
    }
    return 0;
}