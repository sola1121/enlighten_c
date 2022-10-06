# include "stdio.h"


int main(){

    int num;
    double pi, square;

    scanf("%d%lf%lf", &num, &pi, &square);   // 格式化字符连在一起的, 输入时使用空字符分开

    printf("num: %d, pi: %lf, square: %lf\n", num, pi, square);


    // 使用数组模拟字符串
    char array[64] = {'\0'};
    int i = 0;
    scanf("%s", array);   // 注意, 数组名就是一个指针, 且是一个不可修改的常量指针, 其值为第一个元素的内存地址

    for (i=0; i<64&&array[i]!='\0'; i++){
        if (array[i]=='a')   // a变为A, 注意, 数组名和字符串名都是一个不可修改的左值, 而数组中元素可以修改
            array[i] = 'A';
    }
    for (i=0; i<64&&array[i]!='\0'; i++)
        putchar(array[i]);
    putchar('\n');

    return 0;
}