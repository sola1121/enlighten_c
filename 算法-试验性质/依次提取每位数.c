# include "stdio.h"
# include "math.h"


int main(void){
    int num = 807, temp = num;

    temp = num;
    int ret1, ret10, ret100;

    printf("分解num %d\n", num);
    ret1 = temp % (int)pow(10, 1);
    temp -= ret1;
    ret1 /= (int)pow(10, 0);
    printf("ret1 %d, temp %d\n", ret1, temp);

    ret10 = temp % (int)pow(10, 2);
    temp -= ret10;
    ret10 /= (int)pow(10, 1);
    printf("ret10 %d, temp %d\n", ret10, temp);

    ret100 = temp % (int)pow(10, 3);
    temp -= ret100;
    ret100 /= (int)pow(10, 2);
    printf("ret100 %d, temp %d\n", ret100, temp);


    // 仿照上面方法, 从个位利用循环将数拆分

    int count = 1, ret = 0;
    num = 817;   // 这里设定数
    while(1){
        if (num == num % (int)pow(10, count)) break;
        count ++;
    }

    printf("\n这是一个 %d位数\n", count);

    for (int i=1; i<=count; i++){
        ret = num % (int)pow(10, i);
        num -= ret;
        ret /= (int)pow(10,i-1);
        printf("%4d", ret);
    }
    putchar('\n');


    return 0;
}
