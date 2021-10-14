# include "stdio.h"
# include "stdlib.h"


int * create_array(size_t);


int main(){
    int * array = create_array(5);

    if (array == NULL){
        perror("内存分配失败.");
        exit(1);
    }

    array[1] = 2;
    *(array+2) = 3;

    for (int i=0; i<5; i++)
        printf("%d   ", array[i]);

    free(array);   // 释放创建内存

    putchar('\n');
    return 0;
}


// 动态的创建数组, 内存全部初始化为0
int * create_array(size_t len){
    int * array = (int *) malloc(sizeof(int)*len);
    return array;
}