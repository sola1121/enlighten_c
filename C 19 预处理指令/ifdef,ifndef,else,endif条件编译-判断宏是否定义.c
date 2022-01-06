# include "stdio.h"

# define PRLN(value, ...) printf("内容: " #value ", %s\n", __VA_ARGS__)


int main(){
    # define FLAG

    # ifdef FLAG
        PRLN(FLAG, "已定义");
    # else
        PRLN(0, "未定义");
    # endif

    puts("\n将内容取消定义后.");
    # undef FLAG

    # ifdef FLAG
        PRLN(FLAG, "已定义");
    # else
        PRLN(0, "未定义");
    # endif

    puts("\n重新检查定义.");
    # ifndef FLAG
        # define FLAG
        PRLN(FLAG, "已重新定义.");
    # else
        PRLN(FLAG, "定义存在.");
    # endif

    return 0;
}