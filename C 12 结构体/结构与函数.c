# include "stdio.h"
# include "string.h"
# include "time.h"


struct data {
    clock_t time_clock;
    char describe[256];
};


void handle_data1(struct data *);
struct data handle_data2(struct data);
void show_info(const struct data *);


int main(){

    struct data data, *pt_data = &data;
    data.time_clock = clock();
    strncpy(data.describe, "数据来自 初始化", 256);
    show_info(pt_data);

    handle_data1(pt_data);
    show_info(pt_data);

    data = handle_data2(data);
    show_info(pt_data);

    return 0;
}


// 通过修改传入结构指针改变原内容
void handle_data1(struct data * pt){
    pt->time_clock = clock();
    strncpy(pt->describe, "数据来自 handle_data1.", 256);
}


// 通过返回值替换主函数中的对应的内容, 利用同类型结构间可以相互赋值
struct data handle_data2(struct data value){ 
    // 这里的value可是主调函数中对应变量的副本, 是一个仅用于所在函数的新变量
    value.time_clock = clock();
    strncpy(value.describe, "数据来自 handle_data2.", 256);
    return value;
}


// 显示传入的结构数据
void show_info(const struct data * data){
    const char * const format = "%lu, {%s}\n";
    printf(format, data->time_clock, data->describe);
}