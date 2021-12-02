# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"


// TODO: 还有点工作没有做完, main中需要对这些功能进行验证

/* 内存中的数据是后进先出, 而队列中的是先进先出 */


typedef struct queue {
    int data;
    struct queue * front;
    struct queue * rear;
} Queue;


// 插入新队列, 在队列尾端插入新队列
Queue * append_queue(Queue * head, int data){
    Queue * curr,
          * new_node = (Queue *) malloc(sizeof(Queue));

    curr = head;
    new_node->data = data;
    new_node->rear = NULL;

    while (curr->rear != NULL) {
        curr = curr->rear;
    }

    curr -> rear = new_node;
    new_node -> front = curr;

    return head;
}


// 弹出队列, 将队列首端队列弹出(删除)
Queue * popup_queue(Queue * head){
    Queue * curr = head;
    head = curr -> rear;
    head->front = NULL;

    printf("弹出队列首端: 值 - %d\n", curr->data);

    free(curr);

    return head;
}


// 显示队列
void show_queue(Queue * head){
    Queue * curr = head;

    while (curr != NULL){
        printf("%6d", curr->data);
        curr = curr->rear;
    }
    putchar('\n');
}


// 创建队列
Queue * create_queue(int datas[], int arr_len){
    Queue * head = (Queue *) malloc(sizeof(Queue));   // 会创建一个空内存, 且不为NULL, data被赋予值0, 下面得初始化
    head->front = NULL;
    head->rear = NULL;
    head->data = datas[0];

    for (int i=1; i<arr_len; i++){
        head = append_queue(head, datas[i]);
    }

    return head;
}


// 清空队列
void clear_queue(Queue * head){
    Queue * curr = head;
    while (head!=NULL){
        head = curr->rear;
        free(curr);
        curr = head;
    }
}


int main() {

    int datas[10] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};

    Queue * head = create_queue(datas, 10);

    show_queue(head);

    return 0;
}