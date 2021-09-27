# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

# include "common/common.h"

# define ARRLEN 10

/*
    利用二维数组, 直接操作数组来进行排序
*/


// void select_sort(char [][32], int);
void select_sort(char (*)[32], int);

int main(){
    srand((unsigned) time(NULL));

    char arr_str[ARRLEN][_STRLEN];
    puts("生成的字符串数组:");
    for (int i=0; i<ARRLEN; i++){
        strcpy(arr_str[i], generate_string2());
        puts(arr_str[i]);
    }

    select_sort(arr_str, ARRLEN);

    puts("\n排序后的字符串:");
    for (int i=0; i<ARRLEN; i++)
        puts(arr_str[i]);

    return 0;
}


// 使用选择排序法排列字符串
// void select_sort(char arr_str[][_STRLEN], int len){
void select_sort(char (*arr_str)[_STRLEN], int len){
    char temp[_STRLEN];

    for (int m=0; m<len-1; m++){
        for (int n=m+1; n<len; n++){
            if ( strcmp(arr_str[m], arr_str[n])>0 ){
                strcpy(temp, arr_str[m]);
                strcpy(arr_str[m], arr_str[n]);
                strcpy(arr_str[n], temp);
            }
        }
    }

    return;
}
