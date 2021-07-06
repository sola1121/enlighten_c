# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"


typedef struct list {
    int num;
    struct list * next;
} List;


// 插入链表, 向链表头插入节点
List * insert_front_node(List * head, int data){
    if (!head){
        head->num = data;
        head->next = NULL;
        return head;
    }
    
    List * new_node = (List *) malloc(sizeof(List)),
         * temp = head;

    new_node->num = data;
    new_node->next = temp;
    head = new_node;

    return head;
}


// 插入链表, 向链表尾插入节点
List * insert_rear_node(List * head, int data){
    if (!head){
        head->num = data;
        head->next = NULL;
        return head;
    }

    List * new_node = (List *) malloc(sizeof(List)),
         * curr = head;
         
    new_node->num = data;
    new_node->next = NULL;

    while (curr->next != NULL)   // 遍历到链表尾, 用于链接新节点
        curr = curr->next;

    curr->next = new_node;

    return head;
        
}


// 删除链表中对应的节点
List * delete_node(List * head, int data){
    List * prev,  * curr;
    prev = curr = head;

    while (curr != NULL){
        if (curr->num == data){   // 找到与待删数值相等的节点
            if (curr == head)   // 如果该节点是头节点
                head = head->next;
            else 
                prev->next = curr->next;
            free(curr);
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    return head;   // 返回处理过的头, 如果是删的头节点, 这就是新头
}


// 更改链表中对应的节点
bool modify_node(List * head, int old_data, int new_data){
    List * curr = head;

    while (curr != NULL){
        if (curr->num == old_data){
            curr->num = new_data;
            return true;
        }
        curr = curr->next;
    }

    return false;
}


// 查找链表中对应的节点
bool search_node(List * head, int data){
    List * curr = head;

    while(curr->next != NULL){
        if (curr->num == data)
            return true;
        curr = curr->next;
    }

    return false;
}


// 创建链表(初始化链表)
List * create_list(int array[], int arr_len){
    List * head = (List *) malloc(sizeof(List));   // 会创建一个空内存, 且不为NULL, num被赋予值0, 下面得初始化
    head->num = array[0];
    head->next = NULL;

    for (int i=1; i<arr_len; i++)
        head = insert_rear_node(head, array[i]);

    return head;
}


// 遍历链表
void show_list(List * head){
    while(head != NULL){
        printf("%-4d", head->num);
        head = head->next;
    }
    putchar('\n');
}


int main(void) {

    int array[10] = {43, 54, 78, 36, 22, 89, 90, 64, 32, 7};

    List * head = create_list(array, 10);
    puts("创建链表");
    show_list(head);
    putchar('\n');
    
    int to_modify = 22, new_data = 24;
    printf("更改 %d 为 %d, 返回 - %d\n", to_modify, new_data, modify_node(head, to_modify, new_data));
    puts("查看更改后的链表");
    show_list(head);
    putchar('\n');

    int to_search = 89;
    printf("查找 %d 是否存在链表中 - %d\n", to_search, search_node(head, to_search));

    int to_delete = 43;
    head = delete_node(head, to_delete);
    printf("删除 %d, 返回 - %d\n", to_delete, 1);
    show_list(head);
    
    return 0;
}