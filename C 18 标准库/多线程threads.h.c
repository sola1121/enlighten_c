# include "stdio.h"
# include "stdlib.h"

# ifdef __STDC_NO_THREADS__
# error "当前环境不可使用C11标准多线程接口"
# endif

# include "threads.h"


// 用于向线程调用函数传参
typedef struct attr {
    int start;
    int end;
    int step;
    char desc[32];
} * Attr;


// 用于线程执行的函数形式 int(*)(void *)
int fun(void *arg){
    Attr attr = (Attr) arg;
    if (attr->start > attr->end) {
        perror("起始值大于结束值.");
        return 1;
    }

    printf("线程%s, %d ~ %d, 步长%d\n", attr->desc, attr->start, attr->end, attr->step);
    for (int count=attr->start; count<attr->end; count+=attr->step)
        printf("%s - %d\n", attr->desc, count);

    return 0;
}


// 判断线程创建是否成功, 成功创建应为thrd_success, 0
void isSucess(int flag){
    if (flag!=thrd_success){
        perror("创建进程时失败.");
        exit(1);
    }
}


int main(){
    thrd_t th_1, th_2;
    int ret = -1;

    // 传递给线程中执行函数的参数
    struct attr arg_1 = {.start=20, .end=40, .step=2, .desc="th_1"},
                arg_2 = {.start=100, .end=110, .step=1, .desc="th_2"};

    // 创建线程
    ret = thrd_create(&th_1, fun, &arg_1);
    isSucess(ret);
    ret = thrd_create(&th_2, fun, &arg_2);
    isSucess(ret);

    // 接受线程返回值
    int res_1=-1, res_2=-1;

    // 线程挂起, 等待线程执行结束
    thrd_join(th_1, &res_1);
    thrd_join(th_2, &res_2);

    printf("执行完毕, 线程返回值为%d, %d\n", res_1, res_2);

    return 0;
}