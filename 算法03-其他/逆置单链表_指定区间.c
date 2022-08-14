# include "stdio.h"
# include "stdlib.h"

// 头结点占位值
# define HEADDATA -1

// 数据类型
typedef int ElemType;


// 单链表结构体
struct linknode {
    ElemType data;
    struct linknode * next;
};

// 区分链表的结点与指向头结点的指针, 分别定义结点类型和头结点指针类型
typedef struct linknode LinkNode;   // 定义结点类型
typedef struct linknode * LinkList;   // 定义头结点指针类型


// 初始化头结点
LinkList init_list(LinkList head){
    head = (LinkNode *) malloc(sizeof(LinkNode));   // 为头结点动态分配内存
    if (head==NULL)   // 动态分配内存失败
        return NULL;
    
    head->data = HEADDATA;
    head->next = NULL;
    return head; 
}


// 向带有头结点的单链表插入指定值, 采用头插法
LinkList front_insert_node(LinkList head, ElemType value){
    LinkNode * new_node = (LinkNode *) malloc(sizeof(LinkNode));
    if (new_node==NULL)
        return NULL;
    new_node->data = value;
    
    // 头结点后插入新结点
    new_node->next = head->next;
    head->next = new_node;
    return head;
}

// TODO:
// 逆置单链表, 从指定位置, 逆置指定个数的结点
LinkList reverse_between(LinkList head, size_t start, size_t end){
    if (head->next == NULL)   // 空头结点不做处理
        return head;

    LinkNode * start_pt, * end_pt, * curr, * temp;
    size_t count = 1;
    curr = head->next;
    for (; count<start-1 && curr->next!=NULL; curr=curr->next);
    if (curr == NULL)
        return head;
    
    start_pt = curr;
    while (count < end-1 && curr->next!=NULL){
        temp = curr->next;
        temp->next = curr;
        curr = temp;
        count += 1;
    }
    start_pt->next->next = curr;
    start_pt->next = curr;
    curr = curr->next;
    return head;
}


// 输出带有头结点的单链表
void output(LinkList head){
    LinkNode * pt = head->next;
    while (pt!=NULL){
        printf("%-4d", pt->data);
        pt = pt->next;
    }
    putchar('\n');
}


int main(){
    // 声明头结点, 并初始化
    LinkList head;
    head = init_list(head);

    // 创建带有头结点的单链表
    ElemType array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i=0; i<10; i++){
        if (!front_insert_node(head, array[i])){
            perror("创建单链表失败.");
            return EXIT_FAILURE;
        }
    }
    output(head);


    puts("进行部分逆置:");
    reverse_between(head, 3, 6);
    output(head);


    return 0;
}