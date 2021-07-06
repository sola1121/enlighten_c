/* tree.h, 二叉树查找树 */
/* 树中不允许有重复的项 */
# ifndef _TREE_H_
# define _TREE_H_

# include <stdbool.h>

/* 根据具体情况重新定义 Item, 用以存储结构外的需处理的内容 */
# define SLEN 20

typedef struct item {
    char pet_name[SLEN];
    char pet_kind[SLEN];
} Item;

# define MAXITEMS 10

typedef struct tree_node {
    Item item;
    struct tree_node * left;   // 指向左分支的指针
    struct tree_node * right;   // 指向右分子的指针
} TrNode;

typedef struct tree {
    TrNode * root;   // 指向根节点的指针
    int size;   // 树的项数
} Tree;


/* 函数原型 */

// 操作: 把树初始化为空
// 前提条件: ptree指向一个树
// 后置条件: 树被初始化为空
void InitializeTree(Tree * ptree);

// 操作: 确定树是否为空
// 前提条件: ptree指向一个树
// 后置条件: 如果树为空, 该函数返回true, 否则返回false
bool TreeIsEmpty(const Tree * ptree);

// 操作: 确定树是否已满
// 前提条件: ptree指向一个树
// 后置条件: 如果树已满, 该函数返回true, 否则返回false
bool TreeIsFull(const Tree * ptree);

// 操作: 确定树的项数
// 前提条件: ptree指向一个树
// 后置条件: 返回树的项数
int TreeItemCount(const Tree * ptree);

// 操作: 在树中添加一个项
// 前置条件: pitem使待添加项的地址, ptree指向一个已初始化的树
// 后置条件: 如果可以添加, 该函数将在树中添加一个项, 并返回true, 否则返回false
bool AddItem(const Item * pitem, Tree * ptree);

// 操作: 在树中查找一个项
// 前置条件: pitem指向一个项, ptree指向一个已初始化的树
// 后置条件: 如果在树中找到指定项, 该函数返回true, 否则返回false
bool InTree(const Item * pitem, const Tree * ptree);

// 操作: 从树中删除一个项
// 前提条件: pitem使删除项的地址, ptree指向一个已初始化额树
// 后置条件: 如果从树中成功删除一个项, 该函数返回true, 否则返回false
bool DeleteItem(const Item * pitem, Tree * ptree);

// 操作: 把函数应用于树中的每一项
// 前提条件: ptree指向一个树, pfunc指向一个函数, 该函数接受一个Item类型的参数, 并无返回值
// 后置条件: pfunc指向的这个函数为树中的每一项执行一次
void Traverse(const Tree * ptree, void (*pfunc) (Item item));

// 操作: 删除树中的所有内容
// 前提条件: ptree指向一个已经初始化的树
// 后置条件: 数为空
void DeleteAll(Tree * ptree);

# endif