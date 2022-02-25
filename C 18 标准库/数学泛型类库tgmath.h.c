# include "stdio.h"
# include "tgmath.h"

/*
    tgmath.h头文件中将math.h中各种函数通过宏定义和泛型选择重新定义为可以接受不同类型值的宏函数
*/


int main(){
    
    printf("圆周率为: %lf\n", M_PI);
    printf("sin(π/2) = %.2lf  ", sin(M_PI/2));
    printf("sin(π/3) = %.2lf  ", sin(M_PI/3));
    printf("sin(π/4) = %.2lf  ", sin(M_PI/4));
    printf("sin(π/6) = %.2lf\n", sin(M_PI/6));
    printf("cos(π/2) = %.2lf  ", cos(M_PI/2));
    printf("cos(π/3) = %.2lf  ", cos(M_PI/3));
    printf("cos(π/4) = %.2lf  ", cos(M_PI/4));
    printf("cos(π/6) = %.2lf\n", cos(M_PI/6));
    printf("tan(π/2) = %.2lf  ", cos(M_PI/2));
    printf("tan(π/3) = %.2lf  ", cos(M_PI/3));
    printf("tan(π/4) = %.2lf  ", cos(M_PI/4));
    printf("tan(π/6) = %.2lf\n", cos(M_PI/6));

    return 0;
}