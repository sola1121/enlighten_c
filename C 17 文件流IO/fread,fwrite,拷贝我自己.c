# include "stdio.h"
# include "stdlib.h"
# include "string.h"

# define NAMELEN 256 


int main(int argc, char *argv[]){
   // 源文件名, 目标文件名
    char my_name[NAMELEN], new_name[NAMELEN+4];
    strncpy(my_name, argv[0], NAMELEN);
    char *dot_ch;
    dot_ch = strrchr(my_name, '.');
    if (dot_ch == NULL){
        perror("文件名拷贝时出错.");
        exit(EXIT_FAILURE);
    }
    dot_ch[1] = 'c';
    dot_ch[2] = '\0';

    strncpy(new_name, my_name, NAMELEN);
    dot_ch = strrchr(new_name, '.');
    dot_ch[1] = '1';
    dot_ch[2] = 'c';
    dot_ch[3] = '\0';


    FILE *src_fp, *dest_fp;
    size_t bytes, count = 0;
    char temp[64];

    if ( (src_fp=fopen(my_name, "rb")) == NULL ){
        perror("源文件打开失败.");
        exit(EXIT_FAILURE);
    }

    if ( (dest_fp=fopen(new_name, "wb")) == NULL ){
        perror("目标文件打开失败.")
        ;exit(EXIT_FAILURE);
    }

    while ((bytes=fread(temp, sizeof(char), 64, src_fp)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest_fp);
        count += bytes;
    }

    fclose(src_fp); fclose(dest_fp);
    printf("共复制 %lu 字节到 %s\n", count, new_name);
    return 0;
}

