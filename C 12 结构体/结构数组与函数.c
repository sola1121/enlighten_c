# include "stdio.h"

# define format "ISBN: %lu, 书名: %s, 定价: %.1f\n"


struct book{
    unsigned long ISBN;
    char title[256];
    float price;
};

/*
    在作为形参时, 与一般数组并无不同
*/

void show_info(const struct book [], int);

void show_info2(const struct book *, int);


int main(){

    struct book books[2] = {
        {
            9787115521637,
            "C Primer Plus",
            108.0
        },
        {   9787111617935,
            "C程序设计语言",
            30.0
        }
    };

    puts("传入数组名");
    show_info(books, 2);

    puts("\n\n将数组名看作指向数组首地址的指针");
    show_info2(books, 2);

    putchar('\n');
    return 0;
}


void show_info(const struct book books[], int len){
    for (int i=0; i<len; i++)
        printf(format, books[i].ISBN, books->title, books->price);
}


void show_info2(const struct book * books, int len){
    for(int i=0; i<len; i++)
        printf(format, (books+i)->ISBN, (books+i)->title, (books+i)->price);
}