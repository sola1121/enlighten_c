# include "stdio.h"
# include "stdlib.h"

static const size_t ROW = 3;
static const size_t COLUMN = 4;


int main(){
    int (*matrix)[COLUMN];   // 创建一个数组指针

    matrix = (int (*)[COLUMN]) malloc(ROW*COLUMN*sizeof(int));
    // matrix = (int (*)[COLUMN]) calloc(ROW*COLUMN, sizeof(int));

    // 判断是否成功
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
