# include <stdio.h>


int main() {

    char s[] = "abcde";
    char * pt = s+1;   // 指向s[1]

    printf("%c\n", *pt);   // b

    // 先计算括号运算符, 在计算pt++, 结合后计算*pt, 最后pt自增
    printf("%c\n", *(pt++));   // b

    // 上一个计算后, pt指向c, 此处先pt--, 在逗号前完成自增, 指向b, 
    // 再pt++, 因为没有逗号, 所以自增要等整个表达式完成后, 所以指向b的pt计算*, 得出'b', 最后自增, 指向c
    printf("%c\n", *(pt--, pt++));   // b
    
    // 上一个计算后, pt指向c,此处先pt--, 在逗号前完成自增, 指向b, 
    // 在pt++, 后一个运算符是逗号, 完成自增, 指向c, 最后返回最右侧逗号的pt, 与*计算, 得到'c'
    printf("%c\n", *(pt--, pt++, pt));   // c
    

    return 0;

}