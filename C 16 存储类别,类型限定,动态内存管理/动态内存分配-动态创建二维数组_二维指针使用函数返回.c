# include "stdio.h"
# include "stdlib.h"


static const size_t ROW = 3;
static const size_t COLUMN = 4;


int ** create_matrix(size_t, size_t);   // 使用malloc分配内存
int ** create_matrix2(size_t, size_t);   // 使用calloc分配内存


int main(){

    int ** matrix = create_matrix(ROW, COLUMN);   // 使用一个二级指针指向所分配的内存首地址
    // int ** matrix = create_matrix2(ROW, COLUMN);

    if (matrix==NULL){
        perror("内存分配失败.");
        exit(1);
    }

    // 赋值, 指针表示法
    for (int m=0; m<ROW; m++){
        for (int n=0; n<COLUMN; n++){
            *(*(matrix+m)+n) = (m+1)*10 + n + 1;
        }
    }

    // 打印, 数组表示法
    for (int m=0; m<ROW; m++){
        for (int n=0; n<COLUMN; n++)
            printf("%3d", matrix[m][n]);
        putchar('\n');
    }

    free(matrix);
    return 0;
}


// 创建一个二维数组, 并返回
int ** create_matrix(size_t row, size_t column){
    // 分配存储指针的内存
    int ** matrix = (int**) malloc(row*column*sizeof(int*));

    // 为每行数组分配内存
    for (size_t rw=0; rw<row; rw++)
        matrix[rw] = (int*) malloc(column*sizeof(int));
    

    return matrix;
}


// 创建一个二维数组, 并返回
int ** create_matrix2(size_t row, size_t column){
    // 分配存储指针的内存
    int ** matrix = (int**) calloc(row*column, sizeof(int*));

    // 为每行数组分配内存
    for (size_t rw=0; rw<row; rw++)
        matrix[rw] = (int*) calloc(column, sizeof(int));

    return matrix;
}