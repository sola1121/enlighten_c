# include "stdio.h"
# include "stdlib.h"
# include "string.h"

# define NAMELEN 256


int main(int argc, char *argv[]){
    // 源文件名
    char my_name[NAMELEN];
    strncpy(my_name, argv[0], NAMELEN);
    char *dot_ch;
    dot_ch = strrchr(my_name, '.');
    if (dot_ch == NULL){
        perror("文件名拷贝时出错.");
        exit(EXIT_FAILURE);
    }
    dot_ch[1] = 'c';
    dot_ch[2] = '\0';

    int ch;
    unsigned long count = 0;

    FILE *fp;   // 文件指针

    // 只读文本方式打开文件
    if ( (fp = fopen(my_name, "r")) == NULL){
        printf("打开文件 %s 失败.\n", my_name);
        exit(EXIT_FAILURE);
    }

    // 依次遍历文件的字符, 当遇到EOF时候终止
    while ( (ch=getc(fp)) != EOF){
        putc(ch, stdout);   // 将字符写入到stdout中
        count ++;
    }

    fclose(fp);

    printf("\n\n读取文件 %s 共有 %lu 个字符.\n", my_name, count);

    return 0;
}