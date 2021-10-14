# include "stdio.h"

/*
    内部静态变量, 具有文件作用域, 外部链接, 静态存储期
    即从定义处到包含该定义的块的末尾可见, 在所在翻译单元(所在文件)中使用, 在程序执行期间一直存在
*/


int ex_num = 3;

static double ex_array[10] = {100.1, 99.2, 98.3, 97.4, 96.5, 95.6, 94.7, 93.8, 92.9, 91.0};

char ch = 'a';


int main(){

    extern double ex_array[];   // 显式的声明使用外部变量, 可以省略

    for (int i=0; i<10; i++)
        printf("%.2lf   ", ex_array[i]);
    putchar('\n');

    printf("没有重新声明, 隐式使用外部变量: %d\n", ex_num);

    // auto char ch = 'A';   // 显式的声明一个自动变量
    char ch = 'A';   // 块中同名变量, 将会隐藏外部变量
    putchar(ch);

    putchar('\n');
    return 0;
}