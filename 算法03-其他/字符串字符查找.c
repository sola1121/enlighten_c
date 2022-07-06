# include "stdio.h"

/*
    查找字符串中的字符
        char *strchr(const char * str, int ch);
            如果str字符串中包含ch字符, 返回指向str字符串首次初次出现的ch字符的指针(末尾的空字符也是字符串的一部分, 所以在查找范围内)
            如果在str字符串中未找到ch字符, 则返回空指针NULL

        char *strrchr(const char *str, int ch);
            从字符串str尾(右边)开始查找字符ch首次出现的位置(末尾的空字符也是字符串的一部分, 所以在查找范围内)
            如果在str字符串中未找到ch字符, 则返回空指针NULL
*/


# define LEN 14

char * string_search(char *, char ch);


int main(){
    char str[LEN] = "Hello, world.";

    char * pt = string_search(str, 'z');
    if (pt!=NULL)
        printf("在字符串中 %s \n存在字符 %c\n", str, *pt);
    else
        printf("在字符串中 %s \n不存在所找字符\n", str);
    
    return 0;
}


// 返回ch第一次出现在str中的字符指针
char * string_search(char str[], char ch){
    char * pt = str;

    while (*pt!='\0'){
        if (*pt == ch)
            return pt;
        ++ pt;
    }
    return NULL;
}