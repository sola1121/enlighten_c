/* petclub.c 宠物俱乐部花名册, 使用二叉查找树 */
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include "tree.h"


char menu(void){
    int ch;

    puts("Nerfville 宠物俱乐部成员系统");
    puts("输入选项对应字母完成功能选择:");
    puts("a) 添加一个宠物.");
    puts("l) 列出宠物列表.");
    puts("n) 有多少个宠物.");
    puts("f) 查找存在宠物.");
    puts("d) 删除一个宠物.");
    puts("q) 退出程序.");

    while ((ch = getchar()) != EOF){
        while (getchar() != '\n')   // 处理标签剩余内容
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("请输入a, l, f, n, d, q这些字母.");
        else
            break;
    }

    if (ch == EOF)
        ch = 'q';

    return ch;
}


void uppercase(char * str){
    while (*str){
        *str = toupper(*str);
        str ++;
    }
}


char * s_gets(char* st, int n){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');   // 查找换行符
        if (find)
            *find = '\0';   // 将换行符换乘\0
        else
            while (getchar()!='\n')   // 处理输入行的剩余内容
                continue;
    }

    return ret_val;
}


void printitem(Item item){
    printf("Pet: %-19s, Kind: %-19s\n", item.pet_name, item.pet_kind);
}


/* 开始对二叉查找树进行操作 */

void addpet(Tree * pt){
    Item temp;

    if (TreeIsFull(pt))
        puts("没有空间接收.");
    else {
        printf("输入宠物名字: ");
        s_gets(temp.pet_name, SLEN);
        printf("输入宠物种类: ");
        s_gets(temp.pet_kind, SLEN);
        uppercase(temp.pet_name);
        uppercase(temp.pet_kind);
        AddItem(&temp, pt);
    }
}


void showpets(const Tree * pt){
    if (TreeIsEmpty(pt))
        puts("没有内容.");
    else
        Traverse(pt, printitem);
}


void findpet(const Tree * pt){
    Item temp;

    if (TreeIsEmpty(pt)){
        puts("没有内容.");
        return;
    }

    printf("输入需要查找的宠物名: ");
    s_gets(temp.pet_name, SLEN);
    printf("输入查找的宠物种类: ");
    s_gets(temp.pet_kind, SLEN);
    uppercase(temp.pet_name);
    uppercase(temp.pet_kind);

    if (InTree(&temp, pt))
        printf("√ %s, %s, 在查找树中.\n", temp.pet_kind, temp.pet_name);
    else
        printf("× %s, %s, 不在查找树中.\n", temp.pet_kind, temp.pet_name);
}


void droppet(Tree * pt){
    Item temp;

    if (TreeIsEmpty(pt)){
        puts("没有内容.");
        return;
    }

    printf("输入要从名单中删除的宠物名: ");
    s_gets(temp.pet_name, SLEN);
    printf("输入要删除的宠物种类: ");
    s_gets(temp.pet_kind, SLEN);
    uppercase(temp.pet_name);
    uppercase(temp.pet_kind);

    if (DeleteItem(&temp, pt))
        printf("%s, %s, 已经从宠物名单中删除.\n", temp.pet_kind, temp.pet_name);
    else
        printf("%s, %s, 并没有存在于名单中.\n", temp.pet_kind, temp.pet_name);
}


int main(int args, char * argv[]){
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while((choice = menu()) != 'q'){
        switch (choice){
            case 'a': addpet(&pets);
            break;
            case 'l': showpets(&pets);
            break;
            case 'f': findpet(&pets);
            break;
            case 'n': printf("%d pets in club.\n", TreeItemCount(&pets));
            break;
            case 'd': droppet(&pets);
            break;
            default: puts("Switching error.");
        }
    }

    DeleteAll(&pets);
    puts("程序退出.");

    return 0;
}