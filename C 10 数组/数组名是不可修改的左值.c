# include "stdio.h"


int main(){
    int array[] = {1, 2, 3};
    int *pt = array;

    // array ++;   // 数组名是不可修改的左值, 不能修改
    pt ++;   // 指针指向地址, 可以修改指向


    return 0;
}