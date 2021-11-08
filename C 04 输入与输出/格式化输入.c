# include "stdio.h"


int main(){

    int num;
    double pi, square;

    scanf("%d%lf%lf", &num, &pi, &square);   // 格式化字符连在一起的, 输入时使用空字符分开


    printf("num: %d, pi: %lf, square: %lf", num, pi, square);

    return 0;
}