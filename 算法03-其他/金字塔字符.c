# include <stdio.h>

# define HIGH 7


int main() {

    int row, blank, letter;

    for (row=1; row<=HIGH; row++) {
        // 打印空格
        for (blank=HIGH-row; blank>0; blank--) putchar(' ');

        // 打印字符
        for (letter=2*row-1; letter>0; letter--) printf("%c", 'A'+row-1); 

        // 换行
        putchar('\n');
    }


    return 0;
}