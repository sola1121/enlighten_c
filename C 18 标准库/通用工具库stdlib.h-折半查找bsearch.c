# include "stdio.h"
# include "stdlib.h"

# define LEN 12


void show(int * pt, int len){
    for (int i=0; i<len; i++)
        printf("%-4d", *(pt+i));
    putchar('\n');
}


// 比较函数 int (*compar)(const void*, const void*);
int compare(const void * p1, const void * p2){

    const int * a = (const int *) p1;
    const int * b = (const int *) p2;

    if (*a==*b)
        return 0;
    else
        return *a>*b?1:-1;
}


int main(){
    int array[LEN] = {3, 6, 12, 7, 2, 5, 8, 1, 10, 9, 11, 4};
    show(array, LEN);

    // 对于要查找的数组, 首先应该进行排序
    // 使用快速排序
    // 第一个参数, 要排序的数组
    // 第二个参数, 待排序项的个数
    // 第三个参数, 每个元素的大小
    // 第四个参数, 按照什么计算方式排序排序
    qsort(array, LEN, sizeof(int), compare);
    show(array, LEN);

    int * ret = NULL;   // 查找结果
    int key = 5;   // 要查找的元素值

    // 使用二分查找
    // 第一个参数, 要查找的元素值
    // 第二个参数, 要查找的数组指针
    // 第三个参数, 数组中元素的个数
    // 第四个参数, 每个元素的大小, 以字节为单位
    // 第五个参数, 用来比较两个元素的函数
    ret = (int *) bsearch(&key, array, LEN, sizeof(int), compare);

    if (ret != NULL){
        printf("找到元素%p, 值为%d.\n", ret, *ret);
    } else {
        printf("未找到值为%d的元素.\n", key);
    }

    return 0;
}