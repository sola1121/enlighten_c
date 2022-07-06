# include "stdio.h"


/*
杨辉三角
1   
1   1   
1   2   1   
1   3   3   1   
1   4   6   4   1   
1   5   10  10  5   1   
1   6   15  20  15  6   1   
1   7   21  35  35  21  7   1   
1   8   28  56  70  56  28  8   1   
1   9   36  84  126 126 84  36  9   1

行数就是该行元素个数

所有行第一列与最后一列都是1
从第二行开始, 第2列至行的倒数第2列, 所有元素都是所在行的上一行同列元素与该同列元素前一个元素相加的值

*/


# define ROW 9
# define COL ROW


// 打印二维数组
void output(int metrix[][COL], int row, int col){
    for (int m=0; m<row; m++) {
        for (int n=0; n<col; n++) {
            if (metrix[m][n]==0) continue;
            printf("%-5d", metrix[m][n]);
        }
        putchar('\n');
    }
}


int main(){
    
    // 使用一个二维数组来保存杨辉三角
    // 声明一个二维数组并初始化其一二行元素
    int metrix[ROW][COL] = {{1}, {1, 1}};
    puts("初始化: ");
    output(metrix, ROW, COL);

    // 设置所有行的第一列和最后一列都是1
    // 当前行数 = 当前行元素个数
    for (int m=0; m<ROW; m++){
        metrix[m][0] = 1;   // 第一个元素
        metrix[m][m] = 1;   // 最后一个元素
    }

    // 从第三行开始, 每行第二个元素至该行倒数第二个元素, 值为其同列的上一行元素与该上一行元素的前一个元素之和
    for (int m=2; m<ROW; m++){   // 第三行开始
        for (int n=1; n<COL-2; n++){   // 每行的第二个元素到倒数第二个元素
            metrix[m][n] = metrix[m-1][n] + metrix[m-1][n-1];
        }
    }

    puts("\n杨辉三角: ");
    output(metrix, ROW, COL);

    return 0;
}