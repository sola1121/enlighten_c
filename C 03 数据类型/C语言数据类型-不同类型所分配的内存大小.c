# include <stdio.h>
# include <limits.h>
# include <inttypes.h>


/*  
    1比特位只能存储低电压0, 高电压1两种情况
    1字节(byte) = 8比特位(bit)
    1kb = 1024字节(byte)

*/


int main(void) {

    /*  
        在一个通常的64位系统上
        char   所占字节  1, 共有2¹*⁸位
        short  所占字节  2, 共有2²*⁸位
        int    所占字节  4, 共有2⁴*⁸位
        long   所占字节  8, 共有2²*⁸位
        long long 所占字节8, 共有2⁸*⁸位
        float  所占字节  4, 共有2⁴*⁸位, 浮点的工程表示 符号位∪有效数23位∪指数8位, ±1✕有效数✕2⁸
        double 所占字节  8, 共有2⁸*⁸(64)位
        long double 所占字节 16, 共有2¹⁶*⁸位 
    */

    printf("char   所占字节%zd, 最小值 %d, 最大值 %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short  所占字节%zd, 最小值 %d, 最大值 %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int    所占字节%zd, 最小值 %d, 最大值 %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long   所占字节%zd, 最小值 %ld, 最大值 %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long 所占字节%zd, 最小值 %lld, 最大值 %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("float  所占字节%zd, 最小值 %e, 最大值 %e\n", sizeof(float), __FLT_MIN__, __FLT_MAX__);
    printf("double 所占字节%zd, 最小值 %le, 最大值 %le\n", sizeof(double), __DBL_MIN__, __DBL_MAX__);
    printf("long double 所占字节%zd, 最小值 %Le, 最大值%Le\n", sizeof(long double), __LDBL_MAX__, __LDBL_MIN__);


    // 判断整数相加是否溢出
    int num1 = 1000000, num2 = 999999999;
    if (num1 > INT_MAX - num2) {
        printf("\n将会做加法的%d 与 %d 相加将会溢出.\n", num1, num2);
    }


    // 使用转义字符表示的字符常量为变量赋值
    char ch;
    ch = '\101';   // 八进制, 表示字符 A
    printf("使用八进制转义, 对应十进制数值%d, 该字符%c\n", ch, ch);
    ch = '\x61';   // 十六进制, 表示字符a
    printf("使用十六进制转义, 对应十进制数值%d, 该字符%c\n", ch, ch);

    return 0;
}