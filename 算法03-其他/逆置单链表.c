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


// 逆置带有头结点的单链表, 采用头插法
LinkList reverse(LinkList head){
    if (head->next==NULL)
        return head;
    
    LinkNode * curr = head->next, * del_node;
    head->next = NULL;   // 头结点断开和其他结点的连接
    while (curr!=NULL){
        front_insert_node(head, curr->data);
        del_node = curr;
        curr = curr->next;
        free(del_node);   // 将插入完成的结点释放
    }
    return head;
}


// 逆置带有头结点的单链表, 采用双指针法
LinkList reverse2(LinkList head){
    LinkNode * prev, * curr, * temp;
    prev = NULL;
    curr = head->next;

    while (curr!=NULL){
        temp = curr->next;   // 记录下一个位置
        curr->next = prev;   // 反转指向
        prev = curr;   // 反转后, 前一个结点设置为当前结点
        curr = temp;   // 当前结点向后
    }

    head->next = prev;
    return head;
}


// 初始化头结点
LinkList init_list(LinkList head){
    head = (LinkNode *) malloc(sizeof(LinkNode));
    if (head==NULL)   // 动态分配内存失败
        return NULL;
    
    head->data = HEADDATA;
    head->next = NULL;
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
    // 声明并初始化头结点
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

    
    puts("采用前插法逆置链表:");
    reverse(head);
    output(head);


    puts("采用双指针法逆置链表:");
    reverse2(head);
    output(head);


    return 0;
}
