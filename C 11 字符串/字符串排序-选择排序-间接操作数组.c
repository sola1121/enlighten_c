# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

# include "common/common.h"

# define ARRLEN 10

/*  
    使用指针数组指向对应的二维数组内容.
    这意味着pt_str[i]指向arr_str[i]的首字符. 
    每个arr_str[i]都是一个内含32个元素的数组, 每个pt_str[i]都是一个单独的变量.
    通过操作指向字符串的指针, 而不是字符串本身, 完成排序.
*/

void select_sort(char *arr_str[], int len);


int main(){
    srand((unsigned) time(NULL));

    char arr_str[ARRLEN][_STRLEN];
    char *pt_str[ARRLEN];   // 将会记录二维数组的指针数组

    puts("生成的字符串:");
    for (int i=0; i<ARRLEN; i++){
        strcpy(arr_str[i], generate_string2());
        puts(arr_str[i]);
        pt_str[i] = arr_str[i];
    }

    select_sort(pt_str, ARRLEN);
    puts("\n排序后的指针数组:");
    for (int i=0; i<ARRLEN; i++)
        puts(pt_str[i]);

    return 0;
}


// 使用选择排序法对记录字符串的指针排序
void select_sort(char *arr_str[], int len){
    char *temp;

    for (int m=0; m<len-1; m++){
        for (int n=m+1; n<len; n++){
            if ( strcmp(arr_str[m], arr_str[n])>0 ){
                temp = arr_str[m];
                arr_str[m] = arr_str[n];
                arr_str[n] = temp;
            }
        }
    }

    return;
}