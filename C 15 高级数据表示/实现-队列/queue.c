/* queue.c, queue.h的操作实现 */
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "queue.h"

/* 局部函数 */
static void CopyToNode(Item item, Node * pnode);
static void CopyToItem(Node *pnode, Item * pitem);


void InitializeQueue(Queue * pqueue) {
    pqueue->front = pqueue->rear = NULL;
    pqueue->items = 0;
}


bool QueueIsFull(const Queue * pqueue) {
    return pqueue->items == MAXQUEUE;
}


bool QueueIsEmpty(const Queue * pqueue) {
    return pqueue->items == 0;
}


int QueueItemCount(const Queue * pqueue) {
    return pqueue->items;
}


bool EnQueue(Item item, Queue * pqueue) {
    Node * new_node;

    if (QueueIsFull(pqueue))
        return false;

    new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL){
        perror("为新节点分配内存失败.");
        exit(1);
    }

    CopyToNode(item, new_node);   // 将项的内容拷贝到新节点
    new_node->next = NULL;

    if (QueueIsEmpty(pqueue))
        pqueue->front = new_node;   // 当当前队列节点空的时候, 把新的节点设置为队列首端
    else
        pqueue->rear->next = new_node;   // 当当前队列有节点的时候, 将新节点放置在尾端之后

    pqueue->rear = new_node;   // 重新定位新放入的节点为当前尾端
    pqueue->items += 1;   // 项目计数加1

    return true;
}


bool DeQueue(Item * pitem, Queue * pqueue) {
    Node * delete_node;

    if (QueueIsEmpty(pqueue))
        return false;

    CopyToItem(pqueue->front, pitem);   // 将队列的节点中的项拷贝出来
    delete_node = pqueue->front;   // 将要删除的节点指向队列尾端
    pqueue->front = pqueue->front->next;   // 队列的尾端指向下一个尾端
    free(delete_node);   // 释放指向原队列尾端的内存
    pqueue->items -= 1;   // 项数减1

    if (pqueue->items <= 0)   // 删除尾端后, 当前队列没有项了, 设置尾端指向NULL
        pqueue->rear = NULL;
    
    return true;
}


void EmptyTheQueue(Queue * pqueue) {
    Item dummy;
    while (!QueueIsEmpty(pqueue))
        DeQueue(&dummy, pqueue);
}


/* 局部函数 */
static void CopyToNode(Item item, Node * pnode){
    pnode->item = item;
}


static void CopyToItem(Node * pnode, Item * pitem){
    *pitem = pnode->item;
}