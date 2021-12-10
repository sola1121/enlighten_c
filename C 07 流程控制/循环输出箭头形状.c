# include "stdio.h"

# define WIDTH 5   // 箭头宽度
# define HIGHT 5   // 箭头高度

/*
箭头上部分
*****
 *****
  *****
   *****
    *****

箭头下部分
   *****
  *****
 *****
*****

主要是对空格个数的操作
对于上部分箭头, 空格从0随着行数开始递增, 为行数-1
对于下半部分箭头, 空格从当前最高高度-1开始递减, 为行数-1
*/

int main(){

    int row, count, space;   // 打印箭头的行数, 打印*的个数, 打印空格的个数

    // 箭头上部分
    for (row=1; row<=HIGHT; row++){
        for (space=row-1; space>0; space--){
            printf(" ");
        }
        for (count=1; count<=WIDTH; count++){
            printf("*");
        }
        putchar('\n');
    }

    // 箭头下半部分
    for (row=HIGHT-1; row>0; row--){
        for (space=row-1; space>0; space--){
            printf(" ");
        }
        for (count=1; count<=WIDTH; count++){
            printf("*");
        }
        putchar('\n');
    }


    return 0;
}