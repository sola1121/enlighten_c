# include "stdio.h"


int addition(const int x, const int y){
    return x + y;
}


int subtract(const int x, const int y){
    return x - y;
}


int main(){

    int a, b;
    printf("输入两个整数: "); scanf("%d%d", &a, &b);
    while (getchar()!='\n')
        continue;
    
    char ch;
    printf("输入加或减运算符: "); scanf("%c", &ch);
    while (getchar()!='\n')
        continue;

    int (*pt_func)(const int, const int);

    switch(ch){
        case '+':
            pt_func = addition;
            break;
        case '-':
            pt_func = subtract;
            break;
        default:
            puts("输入运算符有误.");
            return 1;
    }

    // int result = (*pt_func)(a, b);   // 通过指针获取其指向的函数后, 在进行调用
    int result = pt_func(a, b);   // 因为函数名是一个指针, 可以直接调用

    printf("运算结果为: %d\n", result);

    return 0;
}