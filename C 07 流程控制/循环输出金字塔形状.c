# include "stdio.h"

/*
如输入5, 打印5层金字塔

    1
   222
  33333
 4444444
555555555

每层输出空格的个数 = 所输入数字 - 当前层数, 如第1层, 有5-1共4个空格, 第2层, 有5-2共3个空格
每层输出子层数的个数 = 当前层数*2 - 1, 如第1层, 有1*2-1共1个, 第2层, 有2*2-1共3个

*/


int main() {
    int number;   // 代表金字塔层数
    printf("输入0~10的一个整数: "); scanf("%d", &number);
    if (number>9 || number<1)
        return 1;

    int layer, space, count;   // 分别代表输出的层数, 空格的个数, 打印层数数字的个数

    for (layer=1; layer<=number; layer++){
        for (space=number-layer; space>0; space--){
            printf(" ");
        }

        for (count=2*layer-1; count>0; count--){
            printf("%d", layer);
        }
        putchar('\n');
    }
    
    return 0;
}