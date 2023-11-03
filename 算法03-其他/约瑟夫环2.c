# include <stdio.h>

/*
    众人围成一个环, 从第一个人开始报数, 数到指定数字的那个人出圈, 他的下一个人又从1开始报数, 数到指定数字的那个人又出圈.
    依此规律重复下去, 直到剩余最后一个胜利者.
*/


# define NUM 10

int main() {
    // 使用数组表示环, 现在都是没有报数的
    int loop[NUM];
    for (int k=0; k<NUM; k++) loop[k]=1;

    int total=NUM,   // 总人数 
        count=0,     // 当前报数
        gap = 3,    // 间隔指定数, 报到该数的人出圈
        i = 0;      // 游标, 从第一个人开始

    printf("总人数: %d, 间隔: %d\n", total, gap);

    while (total>1) {
        if (loop[i] && count==gap) {   // 人没有出圈, 且到了报到了间隔指定数, 该人出圈
            loop[i] = 0;
            count = 0;
            total -= 1;
            printf("第 %d 人出圈\n", i+1);
        }

        if (loop[i])
            count += 1;
        
        i = (i+1)%NUM;
    }

    printf("\n最后剩下:");
    for (int k=0; k<NUM; k++) {
        if (loop[k]) printf(" %d\n", k+1);
    }


    return 0;
}