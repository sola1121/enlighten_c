# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "pthread.h"

# define MAXCOUNT 20


// 将会被执行的函数形式void * (*start_rtn)(void)
void * fun(void *args){
    int step = rand()%MAXCOUNT+1;
    char * desc = (char *) args;

    printf("开始线程%s, 步数为: %d\n", desc, step);
    for(int count=0; count<MAXCOUNT; count+=step)
        printf("%s - %d\n", desc, count);
}


// 判断线程创建是否成功, 成功创建因该为0
void isSucess(int flag){
    if (flag!=0){
        perror("创建进程时失败.");
        exit(1);
    }
}


int main(){
    srand((unsigned) time(NULL));
    int ret = 1;
    pthread_t th_1, th_2;

    // 创建线程
    // 第一个参数, 创建的线程id指针
    // 第二个参数, 创建的线程的属性
    // 第三个参数, 所创创建的线程所执行的函数
    // 第四个参数, 向执行函数中传递参数, void类型
    ret = pthread_create(&th_1, NULL, fun, "th_1");
    isSucess(ret);
    ret = pthread_create(&th_2, NULL, fun, "th_2");
    isSucess(ret);

    // 执行等待
    // 第一个参数, 等待退出的线程id号
    // 第二个参数, 等待退出线程返回值
    pthread_join(th_1, NULL);
    pthread_join(th_2, NULL);

    return 0;
}