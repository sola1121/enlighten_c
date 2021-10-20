# include "stdio.h"
# include "stdlib.h"
# include "string.h"

# define NAMELEN 256
# define CTRL_Z '\032'   // DOS文本文件中的文件结尾


int main(int argc, char *argv[]){
    // 源文件名
    char my_name[NAMELEN];
    strncpy(my_name, argv[0], NAMELEN);
    char * dot_pt = strrchr(my_name, '.');
    if (dot_pt == NULL){
        perror("文件名拷贝时出错.");
        exit(EXIT_FAILURE);
    }
    dot_pt[1] = 'c';
    dot_pt[2] = '\0';

    int ch;
    long count, last;

    FILE *fp;   // 文件指针

    if ( (fp=fopen(my_name, "rb")) == NULL ){   // 二进制模式打开读文件, 可以看到文件中的每一个字符
        perror("文件打开失败.");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);   // 定位到文件末尾
    last = ftell(fp);   // ftell返回当前文件流位置, 当前为为末尾, 使用last记录

    for (count=1L; count<=last; count++){
        fseek(fp, -count, SEEK_END);   // 回退
        ch = getc(fp);
        if (ch!=CTRL_Z && ch!='\r')   // 针对MS-DOS文件, CTRL-Z表示文件尾, \r组合\n表示换行, 不打印
            putchar(ch);
    }

    printf("\n\n读取文件 %s 共有 %lu 个字符.\n", my_name, count);
    fclose(fp);

    return 0;
}

