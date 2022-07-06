# include "stdio.h"


/*
    获取字符串长度
        size_t strlen(const char *);
            返回一个字符串的长度, 不包括空字符
*/

size_t string_length(char * str){
    char * pt = str;
    size_t count = 0;

    while (*pt!='\0'){
        ++ pt;
        ++ count;
    }

    return count;
}


int main(){

    char str[] = "abcdef";

    printf("字符串 %s 的长度 %ld\n", \
            str, string_length(str));


    return 0;
}