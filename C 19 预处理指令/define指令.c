# include "stdio.h"

# define NUMBER_1 24
# define NUMBER_2 NUMBER_1*NUMBER_1   // 宏还可以包含其他宏
# define EXPRESS "hello, world."


int main(){

    printf("%d * %d = %d\n", NUMBER_1, NUMBER_1, NUMBER_2);

    puts(EXPRESS" "EXPRESS" "EXPRESS);

    return 0;
}