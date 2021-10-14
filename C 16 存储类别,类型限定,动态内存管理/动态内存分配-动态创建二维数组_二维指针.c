# include "stdio.h"
# include "stdlib.h"

static const size_t ROW = 3;
static const size_t COLUMN = 4;


int main(){

	int ** matrix;   // 创建一个二级指针
    matrix = (int **) malloc(ROW * sizeof(int*));   // 为第一维指针分配内存, 即各个指向内容的指针
    // matrix = (int **) calloc(ROW, sizeof(int*));
    // 判断是否成功
    if (matrix==NULL){
        perror("内存分配失败.");
        exit(1);
    }
    // 分别为每行数组分配内存
    for (int rw=0; rw<ROW; rw++) {
		matrix[rw] = (int *) malloc(sizeof(int) * COLUMN);
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
