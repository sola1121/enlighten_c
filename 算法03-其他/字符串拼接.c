# include "stdio.h"

/*
    拼接字符串
        char *strcat(char *dest, const char *src);
            把src指向的字符串拷贝至dest指向的字符串末尾. src字符串的第一个字符将覆盖dest字符串末尾的空字符.
            返回dest的值
        注意
            strcat()函数无法检查第一个字符数组是否能容纳第二个字符串. 如果分配给第一个数组的空间不够大, 多出来的字符溢出到相邻存储单元时就会出问题.
            要给拼接后的字符串长度加1才够空间存放末尾的空字符.

        char *strncat(char *dest, const char *src, size_t n);
            把src字符串中的n个字符拷贝至dest字符串末尾. src字符串的第一个字符将覆盖dest字符串末尾的空字符.
            不会拷贝src字符串中空字符和其后的字符, 并在拷贝字符的末尾添加一个空字符.
            返回dest的值
        strcat不能检查目标空间是否能容纳源字符串的副本, 使用strncat可以避免这样的问题.
        可以配合strlen()函数来计算字符串的长度, 应注意一定要留一个空字符的位置.
*/

# define LEN1 64
# define LEN2 129


char * string_concatenate(char *, char *);


int main(){
    char str1[LEN2] = "Make great efforts to be good at ",
         str2[LEN1] = "Python, Golang, Javascript, C, HTML, CSS.";

    string_concatenate(str1, str2);
    printf("拼接后字符串: \n%s\n", str1);

    return 0;
}


// 拼接字符串, 将str2加入到str1的后面
char * string_concatenate(char str1[], char str2[]){
    char * pt1 = str1, *pt2 = str2;

    while (*pt1!='\0')   // 将pt1指向str1最末尾结束符\0字符
        ++ pt1;

    while (*pt2!='\0'){
        *pt1 = *pt2;
        ++ pt1;
        ++ pt2;
    }
    pt1 = '\0';

    return str1;
}