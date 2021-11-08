# include "stdio.h"
# include "stdlib.h"
# include "time.h"


struct data {
    clock_t time_clock;
    char info[32];
};

// 为结构声明类型名, 为一个结构指针
typedef struct data * Data;


// typedef来命名一个结构类型时, 可以省略该结构的标签
typedef struct {time_t time_now; char info[32];} * Data2;


int main() {

    /*
        两个新声明的类型名都是指针类型的, 在实际使用中要使用动态内存分配函数为其分配内存
    */

    Data data_pt1 = (Data) malloc(sizeof(Data)),
         data_pt2 = (Data) malloc(sizeof(Data));

    data_pt1->time_clock = clock();
    data_pt2->time_clock = clock();
    printf("struct data, 数据1: %p, 数据2: %p\n", data_pt1, data_pt2);


    Data2 data2_pt1 = (Data2) malloc(sizeof(Data2)),
          data2_pt2 = (Data2) malloc(sizeof(Data2));

    data2_pt1->time_now = time(NULL);
    data2_pt2->time_now = time(NULL);
    printf("Data2, 数据1: %p, 数据2: %p\n", data2_pt1, data2_pt2);

    free(data_pt1); free(data_pt2);
    free(data2_pt1); free(data2_pt2);

    return 0;
}