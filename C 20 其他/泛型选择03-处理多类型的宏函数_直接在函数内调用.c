# include "stdio.h"

/*
    通过_Generic判断类型, 将函数调用放在泛型表达式内部, _Generic便获得对应函数调用后的返回值
*/


# define GeneralFunction(value) _Generic((value), \
    short: printf("短整型: %hd\n", (value)), \
    int: printf("整型: %d\n", (value)), \
    long: printf("长整型: %ld\n", (value)), \
    float: printf("单精度型: %.2f\n", (value)), \
    double: printf("长精度型: %.2lf\n", (value)), \
    char: printf("字符: %c\n", (value)), \
    char *: printf("字符串: %s\n", (value)), \
    default: puts("不能处理的类型.") \
)


int main(){

    short a = 11;
    int b = 22;
    long c = 33;
    float d = 44.4f;
    double e = 55.5;
    char f = 'f';
    char * g = "ggg";
    int * pt = NULL;

    // 通过_Generic判别输入值的类型, 并获得对应类型的方法调用返回, 在这期间调用了对应类型的函数
    GeneralFunction(a);
    GeneralFunction(b);
    GeneralFunction(c);
    GeneralFunction(d);
    GeneralFunction(e);
    GeneralFunction(f);
    GeneralFunction(g);
    GeneralFunction(pt);

    return 0;
}