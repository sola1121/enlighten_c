# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "unistd.h"
# include "sys/wait.h"


void range(int start, int end, int step){
    for (int count=start; count<end; count+=step)
        printf("%d   ", count);
    putchar('\n');
}


int main(){
    srand((unsigned) time(NULL));

    pid_t process = fork();

    int start = rand()%40+1;
    int end = start+40;
    int step = rand()%4+1;

    if (process==0){
        puts("进入子进程运行");
        range(start, end, step);
    } else if (process>0) {
        printf("当前父进程: %d\n", getpid());
        printf("创建子进程: %d\n", process);
        printf("从%d计数到%d, 步长为%d\n", start, end, step);
        wait(NULL);   // 等待子进程执行完毕
    } else {
        perror("子进程创建失败.");
    }
    
    return 0;
}