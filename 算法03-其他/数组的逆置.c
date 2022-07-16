# include "stdio.h"

# define LEN 10

/*
    逆置所给的数组array
    从开始到数组中间, 交换前部和后部的元素
    i与length-1-i互相交换
*/
void invert(int array[], int length){
    int temp;
    for (int i=0; i<length/2; i++){
        temp = array[i];
        array[i] = array[length-1-i];
        array[length-1-i] = temp;
    }
}


// 打印
void output(int * array, int length){
    for (int i=0; i<length; i++)
        printf("%-4d", array[i]);
    putchar('\n');
}


int main(){

    int array[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    puts("当前数组: ");
    output(array, LEN);

    invert(array, LEN);
    puts("\n逆置后数组: ");
    output(array, LEN);
    

    return 0;
}