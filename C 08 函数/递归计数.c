# include "stdio.h"


// 计数变量是一个具有文件作用域, 外部链接的变量, 即是一个全局变量
// 如果将count写在递归函数当中, 那么每一次其调用的都是函数作用域下的另一个count, 在函数结束后回收
int count = 0;

int count_num(int num){
    if (num>0){
        printf("count - %d, num - %d\n", count, num);
        count += 1;
        count_num(num-1);
    } else {
        printf("最后返回: count - %d, num - %d\n", count, num);
        return count;
    }
}


int main(){

    int ret = count_num(4);

    printf("%d\n", ret);

    return 0;
}