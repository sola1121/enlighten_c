/* list.h -- 单向链表类型的头文件 */
# ifndef LIST_H_
# define LIST_H_

# include <stdbool.h>

/* 数据容器的声明 */

# define TSIZE 63   // 存储电影名的数组大小

struct film {
    char title[TSIZE];
    int rating;
};

/* 一般类型定义 */

typedef struct film Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef Node * List;

/* 函数原型 */

// 操作: 初始化一个链表
// 前提条件: plist指向一个链表
// 后置条件: 链表初始化为空
void InitializeList(List * plist);

// 操作: 确定链表是否为空, plist指向一个已初始化的链表
// 后置条件: 如果链表为空, 返回true; 否则返回false
bool ListIsEmpty(const List * plist);

// 操作: 确定链表是否已满, plist指向一个已初始化的链表
// 后置条件: 如果链表已满, 返回true, 否则返回false
bool ListIsFull(const List * plist);

// 操作: 确定链表中的项数, plist指向一个已初始化的链表
// 后置条件: 返回链表中的项数
unsigned int ListItemCount(const List * plist);

// 操作: 在链表的末尾添加项
// 前提条件: item是一个待添加的项, plist指向一个已初始化的链表
// 后置条件: 向已有链表末尾添加一个项, 返回true; 失败则会返回false
bool AddItem(Item item, List * plist);

// 操作: 把函数作用于链表中的每一项
/*
    plist指向一个已初始化的链表
    pfunc指向一个函数, 该函数接受一个Item类型的参数, 且无返回值
*/
// 后置条件: pfunc指向的函数作用于链表中的每一项一次
void Traverse(const List * plist, void(*pfunc)(Item item));

// 操作: 释放已分配的内存(如果有的话), plist指向一个已初始化的链表
// 后置条件: 释放了为链表所分配的所有内存, 链表设置为空
void EmptyTheList(List * plist);

# endif
