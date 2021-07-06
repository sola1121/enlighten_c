/* test_queue.c, 驱动程序测试 Queue接口 */
/* 链接queueu.c和test_queue.c, 在一起编译 */
# include <stdio.h>
# include "queue.h"


int main(void) {
    Queue line;
    Item temp;
    char ch;

    InitializeQueue(&line);

    puts("测试Queue接口.\n\n");
    puts("a以向队列尾添加内容, d以向队列首删除内容.\nq退出程序.\n");

    while ((ch=getchar()) != 'q'){
        switch (ch) {
            case 'A':
            case 'a':
                printf("输入一个整数: "); scanf("%d", &temp);
                if (!(QueueIsFull(&line))){
                    printf("将 %d 加入队列尾端.\n", temp);
                    EnQueue(temp, &line);
                } else
                    puts("当前队列已满.");
            break;
            case 'D':
            case 'd':
                if (QueueIsEmpty(&line))
                    puts("当前队列没有内容.");
                else {
                    DeQueue(&temp, &line);
                    printf("将 %d 从队列首端移除.", temp);
                }
            break;
            default:
                continue;
        }
        printf("%d items在队列中.\n\n", QueueItemCount(&line));
        puts("a以向队列尾添加内容, d以向队列首删除内容.\nq退出程序.\n");
    }

    EmptyTheQueue(&line);
    puts("退出.");

    return 0;
}