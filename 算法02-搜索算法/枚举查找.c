# include "stdio.h"

# define LEN 10

static int array[LEN] = {32, 54, 76, 23, 54, 65, 76, 89, 97, 4};


int enum_search(int *, int, int);


int main(){

    int to_find1 = 65, to_find2 = 6;

    printf("查找 %d, 位置 %d.\n", to_find1, enum_search(array, LEN, to_find1));
    printf("查找 %d, 位置 %d.\n", to_find2, enum_search(array, LEN, to_find2));

    return 0;
}


// 枚举查找
int enum_search(int array[], int len, int to_find){
    int index = 0;

    for (; index<len; index++){
        if (array[index]==to_find)
            return ++index;
    }

    return -1;
}