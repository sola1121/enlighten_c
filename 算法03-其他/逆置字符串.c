# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"


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


// FIXME:  字符串是不可修改的左值
char * reverse(char * str, int n){
    int len = strlen(str), i = 0;
    char * ret = malloc(sizeof(char)*(len+1));
    while (i<len){
        *(ret++) = str[(n+i++)%len];
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

    puts("逆置字符串:");
    str = reverse(str, strlen(str));
    printf("%s\n", str);
    

    return 0;
}