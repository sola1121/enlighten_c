# include "stdio.h"
# include "string.h"

# define STRSIZE 11


char * get_str(char *, size_t);

int put_str(const char *);


int main(){

    char words[STRSIZE];

    put_str("输入字符串:");

    get_str(words, STRSIZE);

    put_str(words);


    return 0;
}


// 获取字符串
char * get_str(char * str, size_t len){
    size_t i = 0;
    char *find;

    for(; i<len && (str[i]=getchar()) && str[i]!='\n'; i++);   // 遍历输入
    
    find = strchr(str, '\n');   // 查找换行符
    if (find)
        *find = '\0';   // 如果有换行符, 把该处字符替换为空字符

    while (getchar()!='\n')
        continue;

    return str;
}


// 输出字符串
int put_str(const char * str){
    int count = 0;
    while (*str){   // 空字符的数值是0, 在用于表达式判断的时候就是false, 循环将会停止
        putchar(*str++);
        count ++;
    }
    putchar('\n');

    return count;
}