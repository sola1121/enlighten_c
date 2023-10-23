# include <stdio.h>

/*
    乘法表是一个三角矩阵
*/

int main() {

    int row, col;


    for (row=1; row<=9; row++) {
        for (col=9; col>=row; col--)
            printf("%2d*%2d=%2d ", col, row, row*col);
        putchar('\n');
    }

    fputs("\n\n", stdout);

    for (row=9; row>=1; row--) {
        for (col=1; col<=row; col++)
            printf("%2d*%2d=%2d ", col, row, row*col);

        putchar('\n');
    }

    fputs("\n\n", stdout);

    for (row=1; row<=9; row++) {
        for (col=1; col<=row; col++)
            printf("%2d*%2d=%2d ", col, row, row*col);
        putchar('\n');
    }

    return 0;
}