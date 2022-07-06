# include "stdio.h"
# include "stdlib.h"

/*
    深拷贝字符串
        如果pt1和pt2都是指向字符串的指针, pt2=pt1; 代表的就是将pt1指向的地址赋值给pt2, 没有拷贝内容的本身, 属于浅拷贝
        如果希望拷贝整个字符串, 需要用到深拷贝.
    
        char *strcpy(char* str1, const char* str2);
            把str2指向的字符串(包括空字符)拷贝至str1指向的位置
            返回str1的值
        注意
            第一个参数和第二个参数都不必指向数组的开始, 因此可以
                strcpy(words, array+5);
                strcpy(words+2, array);

        char *strncpy(char* str1, const char* str2, size_t n);
            把str2指向的字符串拷贝至str1指向的位置, 拷贝字符数不超过n, 相当于截取str2的n个字符拷贝给str1
            该函数不会拷贝空字符后面的字符
            如果源字符串的字符少于n个, 目标字符串就以拷贝空字符结尾
            如果源字符串有n个或超过n个字符, 就不拷贝空字符
            返回str1的值
        strcpy不能检查目标空间能否容纳源字符串的副本, 使用strncpy可以避免这样的问题.
        可以配合strlen来计算目标数组的长度, 记得一定要为空字符多留一位.
*/


// 将字符串看作数组, 是使用下标遍历进行拷贝
char * string_copy(char str1[], char str2[]){
    // 不检查目标空间str1是否能容纳源字符串

    int i = 0;

    for (i=0; str2[i]!='\0'; i++){
        str1[i] = str2[i];
    }
    str1[i] = '\0';

    return str1;
}


// 将字符串看作内存中连续的内存, 使用指针引用进行拷贝
char * string_copy2(char * str1, char * str2){
    // 不检查目标空间爱str1是否能容纳源字符串

    char *pt1 = str1, * pt2 = str2;
    
    while (*pt2!='\0'){
        *pt1 = *pt2;
        ++ pt1;
        ++ pt2;
    }

    return str1;
}


int main(){
    char str1[32];
    char str2[] = "hello, world.";

    printf("拷贝字符串 %s\n", string_copy(str1, "hello, world."));

    printf("\n拷贝字符串 %s\n", string_copy2(str1, ".dlrow ,olleh"));

    return 0;
}