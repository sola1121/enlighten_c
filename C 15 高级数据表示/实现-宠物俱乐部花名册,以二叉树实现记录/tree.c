/* tree.c 树的支持函数 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "tree.h"


/* 局部数据类型 */
typedef struct pair {
    TrNode * parent;
    TrNode * child;
} Pair;


/* 局部函数类型 */
static TrNode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(TrNode * new_node, TrNode * root);
static void InOrder(const TrNode * root, void (*func)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(TrNode **pptree);
static void DeleteAllNodes(TrNode * ptree);


/* 接口实现 */

void InitializeTree(Tree * ptree){
    ptree->root = NULL;
    ptree->size = 0;
}


bool TreeIsEmpty(const Tree * ptree){
    return ptree->root == NULL ? true : false;
}


bool TreeIsFull(const Tree * ptree){
    return ptree->size == MAXITEMS ? true : false;
}


int TreeItemCount(const Tree * ptree){
    return ptree->size;
}


bool AddItem(const Item * pi, Tree * ptree){
    TrNode * new_node;
    
    if (TreeIsFull(ptree)){
        fprintf(stderr, "树已满.\n");
        return false;
    }

    if (SeekItem(pi, ptree).child != NULL){
        fprintf(stderr, "插入内容已存在.\n");
        return false;
    }

    new_node = MakeNode(pi);
    if (new_node == NULL){
        fprintf(stderr, "创建新节点失败.\n");
        return false;
    }
    ptree->size += 1;   // 通过以上创建, 计数+1

    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    
    return true;
}


bool InTree(const Item * pi, const Tree * ptree){
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}


bool DeleteItem(const Item * pi, Tree * ptree){
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;

    if (look.parent == NULL)   // 删除根节点
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size -= 1;

    return true;
}


void Traverse(const Tree * ptree, void (*pfunc)(Item item)){
    if (ptree != NULL)
        InOrder(ptree->root, pfunc);
}


void DeleteAll(Tree * ptree){
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
        ptree->root = NULL;
        ptree->size = 0;
}


/* 局部函数的实现 */

static void InOrder(const TrNode * root, void (*pfunc)(Item item)){
    if (root != NULL){
        InOrder(root->left, pfunc);
        (*pfunc)(root->item);
        InOrder(root->right, pfunc);
    }
}


static void DeleteAllNodes(TrNode * root){
    TrNode * pright;

    if (root != NULL){
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}


static void AddNode(TrNode * new_node, TrNode * root){
    if (ToLeft(&new_node->item, &root->item)){
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    } else if (ToRight(&new_node->item, &root->item)){
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    } else {
        fprintf(stderr, "AddNode()调用错误, 插入节点时出错.\n");
        exit(1);
    }
}


static bool ToLeft(const Item * i1, const Item *i2){
    int compare;

    if ((compare = strcmp(i1->pet_name, i2->pet_name)) < 0)
        return true;
    else if (compare == 0 && strcmp(i1->pet_kind, i2->pet_kind) < 0)
        return true;
    else
        return false;
}


static bool ToRight(const Item * i1, const Item * i2){
    int compare;

    if ((compare = strcmp(i1->pet_name, i2->pet_name)) > 0)
        return true;
    else if (compare==0 && strcmp(i1->pet_kind, i2->pet_kind) > 0) 
        return true;
    else
        return false;
}


static TrNode * MakeNode(const Item * pi){
    TrNode * new_node;

    new_node = (TrNode *) malloc(sizeof(TrNode));
    if (new_node != NULL){
        new_node->item = * pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}


static Pair SeekItem(const Item * pi, const Tree *ptree){
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;

    while (look.child != NULL){
        if (ToLeft(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->left;
        } else if (ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        } else   // 如果上两种情况都不满足, 则必定是相等的情况, look.child 为目标项的节点
            break;
    }

    return look;
}


static void DeleteNode(TrNode **pptree){
    /* pptree 是指向目标节点的父节点指针成员的地址 */

    TrNode * temp;

    if ((*pptree)->left == NULL){
        temp = *pptree;
        *pptree = (*pptree)->right;
        free(temp);
    } else if ((*pptree)->right == NULL){
        temp = *pptree;
        *pptree = (*pptree)->left;
        free(temp);
    } else {   //MARK: 被删除的节点有两个子节点
        // 找到重新连接右子树的位置
        for (temp = (*pptree)->left; temp->right!=NULL; temp = temp->right)
            continue;
        temp->right = (*pptree)->right;
        temp = *pptree;
        *pptree = (*pptree)->left;
        free(temp);
    }
}