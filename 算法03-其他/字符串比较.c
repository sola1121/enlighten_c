# include "stdio.h"

/*
    比较字符串
        如果直接使用字符数组进行比较, 如 array_string1 == array_string2, 实际上是两个指针的比较, 比较的是这两个指针变量的值是否是同一地址.
        所以这里就需要字符串比较函数来比较两个字符串的内容.
        int strcmp(const char * str1, const char * str2);	
            基于字典顺序比较两个字符串
            如果两个字符串相同, 返回0
            当比较str1与str2相同下标位置的字符, 如果str1的字符在str2的字符前面, 则返回负数, 如果str1的字符在str2的字符后面, 则返回正数.
        补充:
            在前面还是在后面是根据字符码编码值决定的, 一般的为ASCII标准字符码, 其实就是机器排序序列(machine collating sequence), 是按照ASCII标准来的.
            而这个负数一般为-1或者str1[i]-str2[i], 正数为1或者str1[i]-str2[i], 因为-1和1非零, 作为判断表达式的时候为true, if (strcmp(str1, str2)) 如果不等就是真.

        int strncmp(const char * str1, const char * str2, size_t n);
            基于字典顺序比较两个字符串, 最多比较n个字节
            在比较n个字符后或遇到第一个空字符时停止比较

        不同长度的字符串比较
            当比较到某个字符串的结尾的时候, 末尾的后一位是空字符\0, 空字符在ASCII字码最前为0
            所以该字符一定比对位的小, 函数将返回负值.
*/


// 将字符串看作数组, 使用下标遍历进行比较
int string_compare(char str1[], char str2[]){
    size_t m=0, n=0;

    while (str1[m]!='\0' || str2[n]!='\0'){
        if (str1[m] != str2[n])
            return (str1[m]-str2[n]>0?1:-1);
        ++ m;
        ++ n;
    }

    return 0;
}


// 将字符串看作内存中连续的内存, 使用指针引用进行比较
int string_compare2(char * str1, char * str2){
    char * pt1, * pt2;
    pt1 = str1;
    pt2 = str2;

    while (*pt1!='\0' || *pt2!='\0'){
        if (*pt1 != *pt2)
            return (*pt1-*pt2>0)?1:-1;
        ++ pt1;
        ++ pt2;
    }

    return 0;
}


int main(){

    char str1[] = "abcdeff",
         str2[] = "abcdee";


    printf("对比字符串 %s 与 %s, \n结果 %d\n", \
            str1, str2, string_compare(str1, str2));

    return 0;
}