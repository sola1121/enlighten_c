# include "stdio.h"


int main(){

    double dx;
    char cha;
    char chb;
    double dz;
    char chx;
    _Alignas(double) char chz;

    printf("char 的对齐值为: %zd\n", _Alignof(char));
    printf("double 的对齐值为: %zd\n", _Alignof(double));

    printf("dx地址: %p\n", &dx);
    printf("cha地址: %p\n", &cha);
    printf("chb地址: %p\n", &chb);
    printf("dz地址: %p\n", &dz);
    printf("chx地址: %p\n", &chx);
    printf("chz地址: %p\n", &chz);

    return 0;
}