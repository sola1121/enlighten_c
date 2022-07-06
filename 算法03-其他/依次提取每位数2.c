# include "stdio.h"
# include "math.h"

# define NUM 807


int main(){

    int num = 807;

    /*
        每次提取原数最后一位数字, 即个位上的数, 使用原数%10可得个位上的数值
        然后将原数减去已经取了的数值, 在除以10, 让将要取的成为新的个位
    */

    int ret1, ret10, ret100;   // 存储个位, 十位, 百位

    // 提取个位
    ret1 = num % 10;
    num = (num - ret1)/10;

    // 提取十位
    ret10 = num % 10;
    num = (num - ret10*10)/10;
    
    // 提取百位
    ret100 = num%10;
    num = (num-ret100*10)/10;

    // 到最后, 原数会变为一个负数, 以此可以作为循环结束的判断, 并也可以作为统计位数的结束标志
    printf("最后的原数num : %d, 个: %d, 十: %d, 百: %d\n", num, ret1, ret10, ret100);


    /*
        用循环实现
    */
    int temp,   // 记录当前循环提取出来的数
        count = 0;   // 统计位数

    // 使用while循环分离每位数
    putchar('\n');
    num = NUM;
    while (num>=0){
        temp = num % 10;
        if (count==0)   // 针对第一次分离, 减去原数个位时不用乘10
            num = (num - temp) / 10;
        else
            num = (num - temp*10) / 10;
        count ++;
        printf("%-4d", temp);
    }
    printf("\n共 %d 位.\n", count);

    // 使用for循环分离每位数
    putchar('\n');
    num = NUM;
    for (count=0; num>=0; count++){
        temp = num % 10;
        if (count==0)   // 针对第一次分离, 减去原数个位时不用乘10
            num = (num - temp) / 10;
        else
            num = (num - temp*10) / 10;
        printf("%-4d", temp);
    }
    printf("\n共 %d 位.\n", count);


    return 0;
}