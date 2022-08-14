# include "stdio.h"

# define LEN 11

/*  
    约瑟夫环
    已知n个人(以编号1, 2, 3 … n分别表示)围坐在一张圆桌周围
    从第k的人开始报数, 数到指定数字m的那个人出圈, 他的下一个人又从1开始报数, 数到指定数字m的那个人又出圈.
    依此规律重复下去, 直到剩余最后一个胜利者.
*/


// 方式一, 使用一个顺序数组, 依次遍历, 并计数, 每次到指定数字, 将该位置标记, 在重新计数, 以此重复
// 顺序数组array, 开始的报数start, 指定的数字number, 数组的长度length
void loop_out(int array[], int start, int number, size_t length){
    int i = start-1,   // 开始报数的下标
        appoint = number,   // 指定的报数间隔
        count = 0,   // 当前报数
        total = 0;   // 已经报数的人数

    while (total<length){
        if (count==appoint && array[i]!=-1){
            array[i] = -1;
            count = 0;
            total += 1;
        }

        if (array[i]!=-1)
            count += 1;

        if (i>length-1)
            i = 0;
        else
            i += 1;
    }

    printf("共1~%lu, 从%d开始, 报数间隔%d, ", length, start, appoint);
    for (i=0; i<length; i++){
        if (array[i]!=-1)
            printf("最后剩下: %d\n", array[i]);
    }
    putchar('\n');
}


// FIXME:  方式二, 使用递推公式
// https://leetcode.cn/circle/article/BOoxAL/
void loop_out2(int start, int appoint, size_t length){
    int pos = start;
    for (int i=0; i<length; i++){
        pos = (i+appoint)%length;
    }

    printf("\n共1~%lu, 从%d开始, 报数间隔%d, 最后剩下: %d\n", length, start, appoint, pos+1);
}


int main(){
    int array[LEN] = {0};
    puts("当前表示环的数组: ");
    for (int i=0; i<LEN; i++){
        array[i] = i+1;
        printf("%-4d", array[i]);
    }
    putchar('\n');
    loop_out(array, 2, 3, LEN);
    
    // loop_out2(2, 3, LEN);
    

    return 0;
}