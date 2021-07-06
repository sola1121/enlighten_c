/* film.c 使用抽象数据类型(ADT)风格的链表 */
/* 与list.c一起编译 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "list.h"


void showmovies(Item item){
    printf("Movie: %s, Rating: %d\n", item.title, item.rating);
}


char * str_gets(char *st, int n){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');   // 找到换行符
        if (find)   // 找到换行符后, 将该位置的\n变成\0, 让这一行内容变成一个字符串
            *find = '\0';
        else
            while (getchar() != '\n')   // 处理输入行的剩余内容
                continue;
    }
}


int main(int args, char * argv[]){
    List movies;
    Item temp;

    // 初始化
    InitializeList(&movies);
    if (ListIsFull(&movies)){
        perror("Error, 缺少内存.");
        exit(1);
    }

    // 获取用户输入并储存
    printf("输入电影名称(空行停止): ");
    while (str_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0'){
        printf("输入电影评分(0-10): ");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false){
            perror("Error, 在分配内存的时候出错.");
            exit(1);
        }
        if (ListIsFull(&movies)){
            puts("Warnning, 列表已满.");
            break;
        }
        printf("输入电影名称(空行停止): ");
    }

    // 显示
    if (ListIsEmpty(&movies))
        puts("没有输入内容.");
    else {
        puts("输入的电影内容如下:");
        Traverse(&movies, showmovies);
    }

    // 清理
    EmptyTheList(&movies);

    puts("程序退出.");
    return 0;
}