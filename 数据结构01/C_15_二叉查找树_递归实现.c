# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"


typedef struct treenode{
    int num;
    struct treenode * left;
    struct treenode * right;
} TreeNode;


// 向二叉树查找树中插入节点
TreeNode * insert_node(TreeNode * tree, int data){
    if (!tree){   // 递归出口, 为空, 说明根节点无值或递归到叶的子树, 就将其赋值
        tree = (TreeNode *) malloc(sizeof(TreeNode));
        tree->num = data;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }

    if (tree->num > data)
        tree->left = insert_node(tree->left, data);   // 左插入新叶
    else if (tree->num < data)
        tree->right = insert_node(tree->right, data);   // 右插入新叶
    else {
        puts("插入内容已存在.");
        return NULL;
    }

    return tree;
}


TreeNode * delete_node(TreeNode * tree, int data){
    if (!tree)
        return NULL;
    
    if (tree->num > data)
        tree = delete_node(tree->left, data);
    else if (tree->num < data)
        tree = delete_node(tree->right, data);
    else {
        TreeNode * prev, * curr;
        prev = curr = tree;
        if (curr->left == NULL && curr->right == NULL) {  // 为叶节点, 即左右为空
            if (prev == curr)   // 被删除的节点只有根节点
                free(curr);
            else {   // 重新将父节点的左右两边都设置为NULL, 然后释放当前叶
                prev->left = NULL;
                prev->right = NULL;
                free(curr);
            }
        } else if (curr->left != NULL && curr->right == NULL) {   // 有一个节点, 为左节点, 即左边有, 右边空
            if (prev->left == curr)  // 是父节点的左子树
                prev->left = curr->left;
            else                     // 是父节点的右子树
                prev->right = curr->left;
            free(curr);
        } else if (curr->left == NULL && curr->right != NULL) {   // 有一个节点, 为右节点, 即左边空, 右边有
            if (prev->left == curr)  // 是父节点的左子树
                prev->left = curr->right;
            else                     // 是父节点的右子树
                prev->right = curr->right;
            free(curr);
        } else {                                         // 有两个子节点, 即左右两边都有
            TreeNode * succ;   // 下面找前驱
            prev = curr;
            succ = curr->left;

            while (succ->right){
                    prev = succ;   // prev变为记录前驱的父节点, 用于之后将前驱的左节点接上
                    succ = succ->right;
            }

            curr->num = succ->num;   // 用前驱替换待删除的节点数据, 这样之后就只需要将前驱删除

            if (prev == curr)   // 前驱就是待删除节点的左节点, 即该左节点没有右节点了
                prev->left = succ->left;
            else
                prev->right = succ->left;

            free(succ);
        }
    }
    
    return tree;
}


// 在二叉查找树中搜索节点
bool search_node(TreeNode * tree, int data){
    if (!tree)
        return false;

    if (tree->num == data){
        return true;
    }

    if (tree->num > data)
        search_node(tree->left, data);
    else if (tree->num < data)
        search_node(tree->right, data);
}


// 中序遍历二叉树
void inorder(const TreeNode * tree){
    if (tree == NULL)
        return;
    inorder(tree->left);
    printf("%-4d", tree->num);
    inorder(tree->right);
}


// 获取二叉树层高
int tree_height(TreeNode * tree){
    if (tree == NULL){   // 递归出口, 空节点高度为0
        return 0;
    } else {
        int left_height = tree_height(tree->left);
        int right_height = tree_height(tree->right);
        int max = left_height > right_height ? left_height : right_height;
        return max + 1;   // 每递归一层就+1
    }

}


// 创建树(初始化树)
TreeNode * create_tree(int array[], int len){
    TreeNode * bst_root = (TreeNode *) malloc(sizeof(TreeNode));   // 会创建一个空内存, 且不为NULL, num被赋予值0, 下面得初始化
    bst_root->num = array[0];
    bst_root->left = NULL;
    bst_root->right = NULL;

    for (int i=1; i<len; i++)
        insert_node(bst_root, array[i]);

    return bst_root;
}


// 清空树
bool clear_tree(TreeNode * tree){
    if (!tree)
        return true;
    else{
        clear_tree(tree->left);
        clear_tree(tree->right);
        free(tree);
    }
}


int main(void){

    int array[10] = {45, 54, 32, 72, 64, 23, 95, 9, 85, 60};

    TreeNode * bst_root = create_tree(array, 10);
    printf("创建二叉查找树, 完成层高为 %d 的树.\n", tree_height(bst_root));

    puts("\n进行中序遍历");
    inorder(bst_root);
    putchar('\n');

    int to_search = 81;
    printf("查找 %d 是否存在二叉树中 - %d\n", to_search, search_node(bst_root, to_search));

    int to_delete = 72;
    delete_node(bst_root, to_delete);
    printf("进行删除操作 %d, 中序遍历结果:\n", to_delete);
    inorder(bst_root);
    putchar('\n');

    clear_tree(bst_root);

    return 0;
}