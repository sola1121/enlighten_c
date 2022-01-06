# include "stdio.h"


int main(){
    printf("当前行为: %d, 编译的文件为: %s\n", __LINE__, __FILE__);

    puts("\n进行重置行.");

    # line 1
    printf("当前行为: %d, 编译的文件为: %s\n", __LINE__, __FILE__);

    puts("\n进行重置行,文件名.");

    # line 18 "#line指令的使用"
    printf("当前行为: %d, 编译的文件为: %s\n", __LINE__, __FILE__);

    return 0;
}