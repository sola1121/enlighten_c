# include "stdio.h"


int main(){

    int num;

    do {
        printf("输入一个数: "); scanf("%d", &num);
        while (getchar()!='\n');   // 去掉stdin中其他字符
    }while (num <= 0);


    puts("\n使用if判断输入数.");
    if (0<=num && num<100)   // 使用范围对比
        puts("0~100");
    else if (100<=num && num<200)
        puts("100~200");
    else if (200<=num && num<400)
        puts("200~400");
    else if (400<=num && num<800)
        puts("400~800");
    else
        puts(">800");

    
    puts("\n使用switch判断输入数.");
    switch(num/100){   // 取百位对比
        case 0:
            puts("0~100");
            break;
        case 1:
            puts("100~200");
            break;
        case 2:
        case 3:
            puts("200~400");
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            puts("400~800");
            break;
    default:
        puts(">800");
    }

    return 0;
}