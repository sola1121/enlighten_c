# include "stdio.h"


void myself(){
    printf("__LINE__, 当前行数为: %d\n", __LINE__);
    printf("调用 - %s\n", __func__);   // 预定义宏__func__, 在不同函数中代表所在函数名
}


int main(){
    printf("__DATE__,预处理的当前日期: %s\n", __DATE__);
    printf("__FILE__, 当前文件名: %s\n", __FILE__);
    printf("__LINE__, 当前行数为: %d\n", __LINE__);
    printf("__STDC__, 是否遵循C标准: %d\n", __STDC__);
    printf("__STDC_HOSTED__, 是否为本机环境: %d\n", __STDC_HOSTED__);
    printf("__STDC_VERSION__, 支持的标准: %ld\n", __STDC_VERSION__);
    printf("__TIME__, 翻译代码的当前时间: %s\n", __TIME__);

    myself();

    return 0;
}