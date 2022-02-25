# include "stdio.h"

/*
    通过_Generic判断类型, 并在代码中返回相应的函数名, 因为函数名其实就是函数指针
    所以可以通过调用该返回函数名进行函数调用
*/


# define GeneralFunction(value) _Generic((value), \
    short: printshort, \
    int: printint, \
    long: printlong, \
    float: printfloat, \
    double: printdouble, \
    char: printchar, \
    char *: printstring, \
    default: printunkonw \
)


// 打印短整型
void printshort(short);
// 打印整型
void printint(int);
// 打印长整型
void printlong(long);
// 打印单精度型
void printfloat(float);
// 打印双精度
void printdouble(double);
// 打印字符
void printchar(char);
// 打印字符串
void printstring(char*);
// 打印未知类型
void printunkonw(void *);


int main(){

    short a = 11;
    int b = 22;
    long c = 33l;
    float d = 44.4f;
    double e = 55.5;
    char f = 'f';
    char * g = "ggg";
    int * pt = NULL;

    // 先通过_Generic获得函数名, 即函数指针, 然后在调用该函数指针
    // 函数指针调用方式 (*func)(参数) 或 func(参数) 两种方式都可以
    GeneralFunction(a)(a);
    (*GeneralFunction(b))(b);
    GeneralFunction(c)(c);
    (*GeneralFunction(d))(d);
    GeneralFunction(e)(e);
    (*GeneralFunction(f))(f);
    GeneralFunction(g)(g);
    (*GeneralFunction(pt))(pt);

    return 0;
}

void printshort(short num){
    printf("短整型: %hd\n", num);
}


void printint(int num){
    printf("整型: %d\n", num);
}


void printlong(long num){
    printf("长整型: %ld\n", num);
}


void printfloat(float num){
    printf("单精度型: %.2f\n", num);
}


void printdouble(double num){
    printf("双精度型: %.2lf\n", num);   
}


void printchar(char ch){
    printf("字符: %c\n", ch);
}


void printstring(char * string){
    printf("字符串: %s\n", string);
}


void printunkonw(void * pt){
    puts("不能处理的类型.");
}