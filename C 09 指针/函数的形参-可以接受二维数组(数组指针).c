# include "stdio.h"

# define ROW 3
# define COLUMN 4

int sum_matrix1(int [][COLUMN], size_t, size_t);
int sum_matrix2(int (*)[COLUMN], size_t, size_t);


int main(){

    // 二维数组, 在内存中依然是按照一维数组顺序存储的方式保存
    int matrix[ROW][COLUMN] = {11, 12 ,13, 14, 21, 22, 23, 24, 31, 32, 33, 34};

    printf("计算的处二维数组内元素和: %d\n", sum_matrix1(matrix, ROW, COLUMN));
    printf("计算的处二维数组内元素和: %d\n", sum_matrix2(matrix, ROW, COLUMN));

    return 0;
}


// 数组表示法的二维形参, 空的[]只能在做形参时等价与*, 该函数在被调用时, 会被赋值二维数组的首地址
int sum_matrix1(int matrix[][4], size_t row, size_t column){
    int ret = 0;

    for (int rw=0; rw<row; rw++)
        for (int col=0; col<column; col++)
            ret += *(*(matrix+rw)+col);   // 使用指针表示法表示数组

    return ret;
}


// 指针表示法的二维形参, 该函数在被调用时, 会被赋值二维数组的首地址
int sum_matrix2(int (*matrix)[4], size_t row, size_t column){
    int ret = 0;

    for (int rw=0; rw<row; rw++)
        for (int col=0; col<column; col++)
            ret += matrix[rw][col];   // 使用数组表示法表示数组

    return ret;
}