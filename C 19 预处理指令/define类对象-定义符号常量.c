# include "stdio.h"

# define NUM 32

# define RET NUM*NUM   // 嵌套使用宏
# define RET2 NUM * NUM   // 有空格

# define FMT "运算的结果是%d\n"

# define STR1 "字符串内容1"
# define STR2 "字符串内容2"
# define STR STR1 STR2   // 使用两个代表字符串的宏拼接STR宏


int main(){
    const char * fmt = "运算的结果是%d\n";

    printf(FMT, RET);
    printf(fmt, RET);

    puts("\n宏替换体中有空格, 可能被视为字符串一部分, 或者视为记号的分隔符, 对结果没有影响");
    printf(FMT, RET2);

    puts("\n重定义NUM字符常量, 与原定义不同, gcc编译器采用通过编译但是会给出警告");
    #define NUM 1
    printf(FMT, RET);

    printf("\n拼接的字符串\n%s\n", STR);

    return 0;
}