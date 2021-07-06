/* list.c 实现接口, 支持List链表操作的函数具体实现 */

# include <stdio.h>
# include <stdlib.h>
# include "list.h"


// 局部函数原型
static void CopyToNode(Item item, Node * pnode);


// 接口函数
// 把链表设置为空
void InitializeList(List * plist){
    plist = NULL;
}


// 判断链表是否为空, 是则返回true, 否则返回false
bool ListIsEmpty(const List * plist){
    if (*plist == NULL)
        return true;
    else
        return false;
}


// 判断链表是否已满, 是则返回true, 否则返回false
bool ListIsFull(const List * plist){
    Node * pt;
    bool is_full;

    pt = (Node *)malloc(sizeof(Node));   // 通过尝试新建一块内存来判断是否还有内存可以被使用
    if (pt == NULL)
        is_full = true;
    else
        is_full = false;
    
    free(pt);
    return is_full;
}


// 返回节点的数量
unsigned int ListItemCount(const List * plist){
    unsigned int count = 0;
    Node * curr = *plist;

    while (curr != NULL){
        ++count;
        curr = curr->next;
    }

    return count;
}


// 创建存储项的节点, 并将其添加至由plist指向的链表末尾
bool AddItem(Item item, List * plist){
    Node * new_node;
    Node * curr = * plist;

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)   // 判断是否创建成功
        return false;

    CopyToNode(item, new_node);
    new_node->next = NULL;
    if (curr = NULL)   // 空链表, 把新建的放在头
        *plist = new_node;
    else {
        while (curr->next != NULL)   // 将当前链表指针指向链表尾
            curr = curr->next;
        curr->next = new_node;
    }

    return true;
}


// 访问每个节点并对该节点执行pfunc指向的函数
void Traverse(const List * plist, void(*pfunc)(Item item)){
    Node * curr = * plist;
    while (curr != NULL){
        (*pfunc)(curr->item);
        curr = curr->next;
    }
}


// 释放由malloc分配的内存
// 设置链表指针为NULL
void EmptyTheList(List * plist){
    /*
        由于List已经是一个指针, 所以plist是一个指向指针的指针.
        因此, *plist 是指向Node的指针.
        使用free()将当前Node所占用内存释放.
    */
    Node * curr;

    while (*plist != NULL){
        curr = (*plist)->next;
        free(*plist);
        *plist = curr;
    }
}


// 局部函数定义
// 把一个项拷贝到节点中
static void CopyToNode(Item item, Node * pnode){
    pnode->item = item;
}