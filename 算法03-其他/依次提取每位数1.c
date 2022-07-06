# include "stdio.h"
# include "math.h"

# define NUM 807


int main(){
    int num = NUM;

    /*
        在知道所要提取每位的数的位数后
        每次原数%10取其个位, 然后使原数=原数/10, 即消去已取的个位数, 让将取成为新的个位
    */

    // 使用取模统计位数, 当取10的n此模, 余数值==该数, n为该数位数
    int count = 1;   // 位数统计从1开始
    while(1){
        if (num == num % (int)pow(10, count)) break;
        count ++;
    }

    printf("被提取数 %d 为 %d 位数.\n", num, count);

    // 循环取位
    int temp;   // 用来存储当前所提取的位的数值
    while (count>0) {
        temp = num % 10;
        num = (int) (num / 10);   // 使用强制转换, 保证没有变成浮点数
        count --;
        printf("%-4d", temp);
    }
    putchar('\n');
}