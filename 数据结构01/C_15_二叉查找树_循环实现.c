# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"


typedef struct treenode{
    int num;
    struct treenode * left;
    struct treenode * right;
} TreeNode;


// 向二叉查找树中插入节点
bool insert_node(TreeNode * tree, int data){
    TreeNode * new_node = (TreeNode *) malloc(sizeof(TreeNode));
    new_node->num = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (!tree){   // 根节点为空, 为其赋值新节点
        tree = new_node;
        return true;
    }

    TreeNode * prev, * curr;   // prev指向父节点, curr指向当前子节点
    prev = curr = tree;
    
    while (curr != NULL) {
        prev = curr;

        // 查重
        if (curr->num == data)
            return false;
        
        // 一直遍历, 到叶结束(没有内容), 而perv将会记录最后的叶节点, 将prev作为父节点进行插入叶子
        if (curr->num > data)
            curr = curr->left;
        else 
            curr = curr->right;
    }

    // 判断数据应该加入到当前叶节点的左边还是右边
    if (prev->num > data)
        prev->left = new_node;
    else
        prev->right = new_node;
}


// 从二叉查找树中删除节点
bool delete_node(TreeNode * tree, int data){
    // 要处理三个情况, 待删除节点为叶节点, 待删除节点有一个子节点, 待删除节点有两个子节点
    TreeNode * prev, * curr;
    curr = prev = tree;

    while (curr){
        if (curr->num > data){
            prev = curr;
            curr = curr->left;
        } else if (curr->num < data) {
            prev = curr;
            curr = curr->right;
        } else if (curr->num == data) {
            if (curr->left == NULL && curr->right == NULL) {  // 为叶节点, 即左右为空
                if (prev == curr)   // 被删除的节点只有根节点
                    free(curr);
                else {   // 重新将父节点的左右两边都设置为NULL, 然后释放当前叶
                    prev->left = NULL;
                    prev->right = NULL;
                    free(curr);
                }
                return true;
            } else if (curr->left != NULL && curr->right == NULL) {   // 有一个节点, 为左节点, 即左边有, 右边空
                if (prev->left == curr)  // 是父节点的左子树
                    prev->left = curr->left;
                else                     // 是父节点的右子树
                    prev->right = curr->left;
                free(curr);
                return true;
            } else if (curr->left == NULL && curr->right != NULL) {   // 有一个节点, 为右节点, 即左边空, 右边有
                if (prev->left == curr)  // 是父节点的左子树
                    prev->left = curr->right;
                else                     // 是父节点的右子树
                    prev->right = curr->right;
                free(curr);
                return true;
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
                return true;
            }
        }
    }

    return false;
}


// 在二叉查找树中搜索节点
bool search_node(TreeNode * tree, int data){
    if (!tree)
        return false;

    TreeNode * curr = tree;
    
    while (curr != NULL) {
        if (curr->num == data)
            return true;    
        
        if (curr->num > data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return false;
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