# include <stdio.h>

# define LEN 4


void output(const int (*array)[LEN], int length){
    for (int i=0; i<length; i++){
        for (int j=0; j<length; j++)
            printf("%-4d", (*(array+i))[j]);
        putchar('\n');
    }
}


// 将指针指向单个元素地址
void output2(const int (*array)[LEN], int length) {
    const int *pt = &array[0][0];
    for (int i=0; i<length*length; i++) {
        if (i!=0 && i%LEN==0) putchar('\n');
        printf("%-4d", *pt++);
    }
    putchar('\n');
}


// 将指针指向每行的数组
void output3(const int (*array)[LEN], int length) {
    const int (*pt)[LEN] = array;
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {
            printf("%-4d", pt[i][j]);
        }
        putchar('\n');
    }
}


int main() {
    int array[LEN][LEN] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    output2(array, LEN);

    puts("\n矩阵转置:");

    int tmp;
    for (int rw=0; rw<LEN; rw++) {
        for (int col=0; col<rw; col++) {   // 仅需要交换下三角矩阵部分
            tmp = array[rw][col];
            array[rw][col] = array[col][rw];
            array[col][rw] = tmp;
        }
    }

    output2(array, LEN);

    return 0;
}