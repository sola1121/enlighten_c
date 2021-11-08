# include "stdio.h"


enum weeks {
    monday=1,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday,
};


int main(){

    enum weeks num;   // 与 int num无异, 只要能容纳枚举符的范围

input:
    printf("输入星期数字: ");
    scanf("%d", &num);
    while (getchar()!='\n')
        continue;
    if (num < 1 || num > 7)
        goto input;

    switch (num){
        case monday: puts("是星期一.");
            break;
        case tuesday: puts("是星期二.");
            break;
        case wednesday: puts("是星期三.");
            break;
        case thursday: puts("是星期四.");
            break;
        case friday: puts("是星期五.");
            break;
        case saturday: puts("是星期六.");
            break;
        case sunday: puts("是星期日.");
            break;
        default:
            perror("输入数字需要为1~7的整数.");
    }

    return 0;
}
