# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"

/* 
二叉查找树 Binary Search Tree (BST)

属性
    二叉树的每个节点都包含一个项和两个指向其它节点(子节点)的指针.
    二叉树中的每个节点都包含两个子节点, 称左节点和右节点.
    顺序上, 左节点的项在父节点的前面, 右节点的项在父节点的后面.
    左<根<右, 都和根节点比较, 靠前的放左子节点, 靠后的放右子节点.
操作
    插入节点到二叉查找树中
    删除二叉查找树中内节点
    查找二叉查找树中的某个节点
*/


/*=====================数据抽象: 数据内容+树结构=======================*/

// 用以存储的内容, 存储整数和字符串, 整数要求不重复
typedef struct content {
    int num;
    char str[31];
} Content;


// 用以构建的结构, 定义节点, 包含左右子树结构, 存储的内容Content
typedef struct treenode {
    Content content;
    struct treenode * left;
    struct treenode * right;
} TreeNode;


// 还可以在封装一层, 专门表示二叉查找树, 当然在上面的就可以满足使用了
// 用来专门指向根节点的TreeNode封装
    typedef struct binary_search_tree {
        TreeNode * root;
        int size;   // 记录数据多少, 每插入或删除就进行一次计数
    } BSTree;

/*
    说明, 在使用数据的时候, 用户只需要和TreeNode BSTree和Content进行交互.
    即只需要了解树的根节点和要用的内容数据, 就可以, 树的结构构成将被各种操作隐藏.
*/

/*=====================抽象接口: 对数据结构的使用=======================*/

// 向二叉查找树tree中插入新节点, 内容为item
bool insert_node(TreeNode * tree, Content * item);


/*
    1. 删除的是叶子结点, 直接删除, 再修改其父结点指针指向NULL
    2. 删除的节点有一个子节点, 可以将该子节点作为被删除节点的父节点的对因位置的子节点连接
    3. 删除的节点有两个子节点.
        找前驱节点, 即待删除节点左子树的最右边(中序遍历紧靠待删除值左边的), 将前驱节点的值替换待删除的值
        如果前驱节点有左子树(不可能存在右子树, 因为其本身就是最右), 将该右子树接到前驱节点父节点的右边
        或
        找后继节点, 即待删除节点右子树的最左边(中序遍历紧靠待删除值右边的), 将后继节点的值替换待删除的值
        如果后继节点有右子树(不可能存在左子树, 因为其本身就是最左), 将该右子树接到后继节点父节点的左边
        最后释放后继节点
    需要牢记 - 每个节点比它左子树的节点值都要大, 而比右子树的节点值都要小
*/
// 从二叉查找树中删除对应内容的节点
bool delete_node(TreeNode * bst_root, Content * item);


// 向二叉查找树tree中查找内容为item的节点
bool search_node(TreeNode * tree, Content * item);


/*=========================遍历二叉查找树结构=======================*/

// 前序遍历
// 首先访问根结点然后遍历左子树, 最后遍历右子树. 根->左->右.
/*
    如果二叉树为空则结束返回.
    否则
        1.访问根结点.
        2.前序遍历左子树.
        3.前序遍历右子树.
*/
void preorder_traversal(const TreeNode * tree){
    if (tree == NULL)
        return ;

    printf("%-4d", tree->content.num);
    preorder_traversal(tree->left);
    preorder_traversal(tree->right);
}


// 中序遍历
// 首先遍历左子树, 然后访问根结点, 最后遍历右子树. 左->根->右
/*
    如果二叉树为空则结束返回.
    否则
        1.中序遍历左子树
        2.访问根结点
        3.中序遍历右子树
*/
void inorder_traversal(const TreeNode * tree){
    /* 在二叉查找树中可用来排序, 复杂度O(logN) */
    if (tree == NULL)
        return ;
    
    inorder_traversal(tree->left);
    printf("%-4d", tree->content.num);
    inorder_traversal(tree->right);
}


// 后序遍历
// 首先遍历左子树, 然后遍历右子树, 最后访问根结点. 左->右->根. 
/*
    如果二叉树为空则结束返回.
    否则
        1.后序遍历左子树
        2.后序遍历右子树
        3.访问根结点
*/
void postorder_traversal(const TreeNode * tree){
    if (tree == NULL)
        return ;
    
    postorder_traversal(tree->left);
    postorder_traversal(tree->right);
    printf("%-4d", tree->content.num);
}


// 层次遍历
/*
    根节点入队列, 并入队列一个特殊的标识位,此处是 null 出队列.
    判断是不是 null, 如果是则代表本层已经结束. 再次判断是否当前队列为空, 如果不为空继续入队一个 null, 否则说明遍历已经完成, 什么都不不用做
    如果不为 null, 说明这一层还没完, 则将其左右子树依次入队列.
*/
void layerorder_traversal(const TreeNode * bst_root);
