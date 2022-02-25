# include "stdio.h"
# include "stdarg.h"


double sum(int, ...);


int main(){
    double s, t;

    s = sum(3, 1.1, 2.5, 13.3);   // 对3个参数进行求和
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);   // 对6个参数进行求和
    printf("s = %g\n", s);
    printf("t = %g\n", t);

    return 0;
}


double sum(int lim, ...){
    va_list ap;   // 声明一个初始化为参数列表
    double tot = 0;
    int i;

    va_start(ap, lim);   // 把ap初始化为参湖列表
    for (i=0; i<lim; i++)
        tot += va_arg(ap, double);   // 访问参数列表中的每一项
    va_end(ap);   // 清理工作

    return tot;
}