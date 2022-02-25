# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"


// 用来向线程调用的函数传递参数
struct attr {
    int start;
    int end;
    int step;
    char desc[64];
};

typedef struct attr * Attr;


// 将会被执行的函数形式void * (*start_rtn)(void)
void * fun(void * args){
    Attr attr = (Attr) args;

    printf("线程%s, 从%d~%d, 步长%d.\n", attr->desc, attr->start, attr->end, attr->step);
    for (int count=attr->start; count<attr->end; count+=attr->step)
        printf("%s - %d\n", attr->desc, count);
}


// 判断线程创建是否成功, 成功创建因该为0
void isSucess(int flag){
    if (flag!=0){
        perror("创建进程时失败.");
        exit(1);
    }
}


int main(){
    int ret = 1;
    pthread_t th_1, th_2;
    struct attr arg_1 = {.start=10, .end=30, .step=3, .desc="th_1"},
                arg_2 = {.start=60, .end=70, .step=2, .desc="th_2"};

    // 创建线程
    // 第一个参数, 创建的线程id指针
    // 第二个参数, 创建的线程的属性
    // 第三个参数, 所创创建的线程所执行的函数
    // 第四个参数, 向执行函数中传递参数, void类型
    ret = pthread_create(&th_1, NULL, fun, &arg_1);
    isSucess(ret);
    ret = pthread_create(&th_2, NULL, fun, &arg_2);
    isSucess(ret);

    // 执行等待
    // 第一个参数, 等待退出的线程id号
    // 第二个参数, 等待退出线程返回值
    pthread_join(th_1, NULL);
    pthread_join(th_2, NULL);

    return 0;
}