# include "stdio.h"
# include "string.h"


struct bottom {
    double thickness;
    double radius;
};


struct lid {
    double weight;
    char info[32];
};


// 瓶子, 每次只表示瓶盖或瓶底
struct bottle {
    int part;   // 瓶盖对应0, 瓶底对应1
    // 使用一个匿名联合, 每次只表示瓶子的一部分, 即要么是瓶盖, 要么是瓶底
    union {
        struct bottom bottom;
        struct lid lid;
    };
};


int main(){

    struct bottle b = {.part=0};

    if (b.part==0) {
        b.lid.weight = 5.3;
        strncpy(b.lid.info, "再来一瓶", 32);
    } else if (b.part==1){
        b.bottom.thickness = 7.6;
        b.bottom.radius = 35;
    } else {
        perror("瓶子部分数字超出表示范围.");
        return 1;
    }


    if (b.part==0) {
        puts("将会生产瓶子的盖子.");
        printf("盖体重量: %.4lfg, 印有: %s\n", b.lid.weight, b.lid.info);
    } else if (b.part==1) {
        puts("将会生产瓶子的底部.");
        printf("瓶底厚度: %.4lfmm, 半径: %.4lfcm\n", b.bottom.thickness, b.bottom.radius);
    }


    return 0;
}