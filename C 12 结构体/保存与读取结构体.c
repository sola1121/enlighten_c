# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "stdbool.h"

# define CHSIZE 128
# define format "ISBN: %lu, 书名: %s, 作者: %s\n\n"


// 结构: 书, 成员: ISBN, 书名, 作者
struct book {
    unsigned long ISBN;
    char title[CHSIZE];
    char author[CHSIZE];
};


int extract_struct(char *, struct book [], int len);

struct book * derive_struct(char *, int);

void show_books(const struct book *, int);


int main(int argc, char * argv[]){

    // 将要保存的数据
    struct book books[3] = {
        {
            9787115390592,
            "C Primer Plus",
            "Stephen Prata"
        },
        {
            9787111128069,
            "C程序设计语言",
            "Brian W. Kernighan / Dennis M. Ritchie"
        },
        {
            9787115167071,
            "C语言程序设计现代方法",
            "金"
        }
    };


    // 将要保存到的文件
    char filepath[512], *dot_pt;
    strncpy(filepath, argv[0], 512);
    dot_pt = strrchr(filepath, '.');
    dot_pt[1] = 'd';
    dot_pt[2] = 'a';
    dot_pt[3] = 't';
    dot_pt[4] = '\0';
    printf("内容将导出到: %s\n", filepath);


    // 从文件中写结构部分
    if ( extract_struct(filepath, books, 3) == false)
        perror("导出到文件时出现错误");
    else
        puts("导出到文件成功");


    // 从文件中读结构部分
    struct book * pt_books;
    pt_books = derive_struct(filepath, 2);   // 只选择从文件中读取2个结构
    if (pt_books==NULL)
        perror("获取文件时出现错误");
    else {
        puts("读取文件成功\n");
        show_books(pt_books, 2);
    }

    free(pt_books);

    return 0;
}


// 将数组中指定个数的结构保存到文件当中
int extract_struct(char * path, struct book data[], int len){
    if (!data)
        return false;

    FILE * fp;
    if ((fp=fopen(path, "wb"))==NULL)
        return false;

    for (int i=0; i<len; i++)
        fwrite(data+i, sizeof(struct book), 1, fp);   // 每次写入一个struct book大小的数据

    fclose(fp);
    return true;
}


// 从文件中获取指定个数个保存的结构内容
struct book * derive_struct(char * path, int len){
    FILE * fp;
    if ((fp=fopen(path, "rb"))==NULL)
        return NULL;

    struct book * ret = (struct book *) calloc(len, sizeof(struct book));
    if (ret==NULL)
        return NULL;

    for (int i=0; i<len; i++){
        fread(ret+i, sizeof(struct book), 1, fp);   // 每次读出一个struct book大小的数据
    }
    
    fclose(fp);
    return ret;
}


// 显示结构数组内容
void show_books(const struct book * pt, int len){
    for (int i=0; i<len; i++)
        printf(format, (pt+i)->ISBN, (pt+i)->title, (pt+i)->author);
}