# include "stdio.h"


int main(){
    int num = 255;
    float pi = 3.1415;
    double square = 546.89;

    printf("默认右对齐输出: %6d | 使用-表示左对齐: %-6d, 显示占位0与正负: %+06d\n", num, num, num);

    printf("八进制输出: %o, %#o\n", num, num);

    printf("十六进制输出: %X, %#x\n", num, num);


    // 浮点数输出数字位数, 先要满足最小字段宽度, 实际超出以实际为准 , 然后小数点后的再满足精度
    printf("浮点数最小字段宽度.精度: %5.4f, %5.2f\n", pi, square);
    printf("浮点数最小字段宽度与精度都小于实际: %4.3f, %4.1f\n", pi, square);
    printf("浮点数最小字段宽度小于实际, 但是精度大于实际: %4.5f, %1.3f\n", pi, square);
    printf("浮点数最小字段宽度大于实际: %12.6f, %12.6f\n", pi, square);


    printf("浮点数使用e记数法: %e, %E, %12e\n", pi, square, square);

    printf("根据浮点数值不同, 自动选择: %g, %g, %G\n", pi, square, square*346237.98);

    return 0;
}