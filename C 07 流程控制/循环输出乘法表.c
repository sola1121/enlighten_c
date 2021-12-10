# include "stdio.h"

/*

打印九九乘法表

*    1    2    3    4    5    6    7    8    9    
1    1    
2    2    4    
3    3    6    9    
4    4    8    12   16   
5    5    10   15   20   25   
6    6    12   18   24   30   36   
7    7    14   21   28   35   42   49   
8    8    16   24   32   40   48   56   64   
9    9    18   27   36   45   54   63   72   81   


第一行单独打印
从第二行开始, 首先输出当前行号, 然后输出当前行与列乘积, 当行数与列数相同时候, 结束当前行进行下一行

*/


int main(){
    int row, column;

    // 打印第一行
    for (int i=0; i<=9; i++){
        if (i==0) printf("*    ");
        else printf("%-5d", i);
    }
    putchar('\n');

    // 首先打印但前行号, 在遍历列直到与行号相同, 同时输出乘积
    for (row=1; row<=9; row++){
        printf("%-5d", row);
        for (column=1; column<=row; column++){ 
            printf("%-5d", row*column);
        }
        putchar('\n');
    }

    return 0;
}