# include "stdio.h"
# include "unistd.h"
# include "time.h"

# define format "编号 %lu, 数据{%ld, %s}\n"


int main(){

    struct data {
        clock_t time_clock;
        char describe[256];
    };

    struct list {
        size_t count;
        struct data data;
    };

    struct list values[2] = {
        {
            .count=1, 
            {clock(), "data 1"},
        },
        {
            .count = 2,
            {clock(), "data 2"},
        },
    };


    struct list * pt;   // 指向结构的指针


    pt = &values[0];   // 指向结构数组第一个
    printf(format, (*pt).count, (*pt).data.time_clock, (*pt).data.describe);

    sleep(1);

    pt++;   // 指向结构数组第二个
    printf(format, (*pt).count, pt->data.time_clock, pt->data.describe);


    return 0;
}