#include "stdio.h"
#include "ctype.h"
#include "string.h"


void Upper(char *);   // 字符串转换为大写
void Lower(char *);   // 字符串转换为小写
void Trans(char *);   // 字符串大小写相互转换
void Dummy();   // 不做处理

void show(char *, void (*)(char *));   // 使用不同方法显示字符串


int main(){

    char string[32] = "AbcDEFghIjkLMNopQrstUVWxyz",
         ch;

    printf("选择显示的方法, u-大写, l-小写, t-转换, d-不做处理: "); scanf("%c", &ch);
    while(getchar()!='\n');

    /*
        检查输入字符是否在要求中
        if (strchr("ultd", ch)==NULL) perror("不再要求字符中.");
    */

    void (* pt_func) (char *);   // 声明函数指针, 被指向的函数接受char*类型的参数, 无返回值

    switch (ch){
        case 'U':
        case 'u':
            pt_func = Upper;
            break;
        case 'L':
        case 'l':
            pt_func = Lower;
            break;
        case 'T':
        case 't':
            pt_func = Trans;
            break;
        case 'D':
        case 'd':
            pt_func = Dummy;
            break;
        default:
            puts("未知字符, 停止程序.");
            return 0;
    }

    show(string, pt_func);   // 根据选择, 使用不同的函数以打印输出

    putchar('\n');
    return 0;
}


// 字符串转换为大写
void Upper(char * string){
    while (*string){
        *string = toupper(*string);
        string++;
    }
}


// 字符串转换为小写
void Lower(char * string){
    while (*string){
        *string = tolower(*string);
        string++;
    }
}


// 字符串大小写相互转换
void Trans(char * string){
    while (*string){
        if (islower(*string))
            *string = toupper(*string);
        else if (isupper(*string))
            *string = tolower(*string);
        string++;
    }
}


// 不做任何转换
void Dummy(char * string){}


// 根据选择显示不同形式字符串
void show(char * string, void (* func_pt)(char * string)){
    (* func_pt)(string);
    puts(string);
}
