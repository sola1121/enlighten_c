# include "stdio.h"

# define SQUARE(X) ((X)*(X))
# define PSQR(X) printf("square = " #X " * " #X " 运算结果为: %d\n", ((X)*(X)))   // 字符串化

# define XNAME(N) X ## N
# define PRINT_XN(N) printf("X" #N " = %d\n", X ## N)   // 黏和X和参数形成新的字符用来替换

# define PR(X, ...) printf("变量名: " #X ", 内容为: " __VA_ARGS__)   // 使用变参宏


int main(){

    int num = 5;

    printf("平方为%d\n", SQUARE(num));

    PSQR(num);

    int XNAME(1) = 14;   // 变为 int X1 = 14;
    int XNAME(2) = 20;   // 变为 int X2 = 20;
    int X3 = 30;
    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);

    PR(X3, "%d\n", X3);

    return 0;
}