# include "stdio.h"
# include "math.h"

# define NUM 807

/*
    使用递归实现每次取个位, 并除10将下一位待取数放到个位
*/

void get_digit(int num){
    if (num==0)
        return;

    printf("%-4d", num%10);
    get_digit((int)(num/10));
}


int main(){
    int num = NUM;

    /*
        每次原数%10取其个位, 然后使原数=原数/10, 即消去已取的个位数, 让将取位成为新的个位
    */

    get_digit(num);

    putchar('\n');
}