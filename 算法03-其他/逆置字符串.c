# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

/*
    NOTE: 因为字符串是不可修改的左值, 所以, 逆置字符串不能在原来的字符串上进行
    当然可以使用字符数组代替字符串
*/


char * rand_string(){
    int len = rand()%127 + 1;
    char * ret = (char *) malloc(sizeof(char)*len),
         ch;
    for (int i=0; i<len; i++){
        ch = 97 + rand()%26;
        ret[i] = ch;
    }
    ret[len-1] = '\0';
    return ret;
}


// 逆置长度为n的字符串str
char * reverse(char * str, int n){
    int len = strlen(str), i = 0;
    char * ret = malloc(sizeof(char)*(len+1));   // 分配新的连续空间, 用来存储字符数组
    while (i<len){
        *(ret++) = str[(n-1-i++)%len];   // 依次进行赋值
    }
    *ret = '\0';
    return ret - len;
}


int main(){
    srand((unsigned)time(NULL));

    char * str;

    puts("生成的字符串:");
    str = rand_string();
    printf("%s\n", str);

    puts("\n逆置字符串:");
    str = reverse(str, strlen(str));
    printf("%s\n", str);
    

    return 0;
}