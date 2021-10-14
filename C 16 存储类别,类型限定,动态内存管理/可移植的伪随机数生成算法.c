/*
    ANSI C标准提供的可以只的伪随机数生成算法

    随机种子是一个具有内部链接的静态变量, 具有文件作用域, 内部链接, 静态存储期
    即从他的定义处到该定义所在文件的末尾均可见, 能在所在翻译单元(所在文件)中使用, 在程序执行期间一直存在.

    函数默认是文件作用域, 外部链接, 静态存储期
    即从他的定义处到该定义所在文件的末尾均可见, 能在多个翻译单元(不同文件)中使用, 在程序执行期间一直存在.

    该文件需要与其他文件一起编译使用, 其他文件中应该包含一个main函数
*/


static unsigned long int next = 1;   // 随机种子


// 返回一个0~32767直接按的值
unsigned int rand_uint(void){
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}


// 设置随机种子
void srand_uint(unsigned int seed){
    next = seed;
}


/*

    通常使用time获取系统时间来运行每次不同的伪随机

    # include "time.h"

    srand_uint((unsigned) time(NULL));
*/