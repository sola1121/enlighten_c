# include "stdio.h"
# include "string.h"

# define STRLEN 256


int main(int args, char * argv[]){

    char content[STRLEN];

    puts("content拷贝argv第一个数组(是一个字符串):");
    strcpy(content, argv[0]);
    puts(content);

    *content = '\0';

    puts("content拷贝从argv第一个数组中第二个字符开始拷贝:");
    // strcpy(content, *argv+1);
    //strcpy(content, *(argv+0)+1);
    strcpy(content, argv[0]+1);
    puts(content);

    *content = '\0';

    puts("从content第四个元素开始拷贝argv第一个数组(是一个字符串):");
    strcpy(content+3, argv[0]);

    puts(content);   // 因为content[0]保存一个空字符'\0', puts()看到这个空字符便结束, 并打印一个换行符
    puts(content+3);   // content从第四个元素开始保存argv第一个数组的内容, 在这里将会打印内容

    *content = '\0';

    strcpy(content, (char [10]){'\n', 'd', 'o', 'n', 'e', '.', '\0'});
    puts(content);

    *content = '\0';
    
    strcpy(content, "\n使用字符串字面量可以将中文存储.");
    puts(content);

    memset(content, 0, STRLEN);
    /*
        其实在内存中对应的位置的那些字符串都没有被处理, 只是在不断的变换.
        先在使用memset将字符串数组起始位置到结束, 全部重置为0, 即空字符.
    */

    puts("拷贝第二个参数前5个字符:");
    strncpy(content, "hello, world.", 5);
    puts(content);


    return 0;
}