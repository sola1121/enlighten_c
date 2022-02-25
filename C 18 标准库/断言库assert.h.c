# include "stdio.h"
# include "math.h"
# include "assert.h"

/*
    在求平方根之前, 该程序断言z是否大于或等于0.
    程序还错误地减去一个值而不是加上一个值, 故意让z得不到合适的值
*/


int main(){
    double x, y, z;

    puts("输入一对数字(0 0退出): ");
    while(scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y !=0)){
        z = x * x - y * y;   // 应该用 +
        assert(z >= 0);   // 使用断言宏函数, 需要满足z大于或等于0
        printf("计算结果为: %f\n", sqrt(z));
        puts("输入下一对数字: ");
    }

    return 0;
}