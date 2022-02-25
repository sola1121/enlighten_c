# include "stdio.h"
# include "math.h"

/*
    通过泛型选择, 根据参数类型选择最合适的数学函数版本
*/

# define RAD_TO_DEG (180/(4*atan(1)))   // 弧度转换为角度

// 将参数传递给获得的函数名, 即通过函数指针调用所指向函
# define SQRT(value) _Generic((value), \
    long double: sqrtl, \
    default: sqrt, \
    float: sqrtf) (value)

// 在宏函数内部使用对应名称的函数, 获得函数调用后的值
# define SIN(value) _Generic((value), \
    long double: sinl((value)/RAD_TO_DEG), \
    default: sin((value)/RAD_TO_DEG), \
    float: sinf((value)/RAD_TO_DEG) \
)


int main(){
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;

    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);

    printf("%.17Lf\n", y);   // 匹配float
    printf("%.17Lf\n", yy);   // 匹配default
    printf("%.17Lf\n", yyy);   // 匹配long double

    int num = 45;
    yy = SQRT(num);   // 匹配default
    printf("%.17Lf\n", yy);

    yyy = SIN(xxx);   // 匹配long double
    printf("%.17Lf\n", yyy);

    return 0;
}
