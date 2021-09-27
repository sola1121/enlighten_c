# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

# include "common.h"


// 随机生成等长字符串
char * generate_string(){
    char *ret = (char *) malloc(sizeof(char)*_STRLEN);
    char ch = '\0';

    for (int i=0; i<_STRLEN; i++){
        ch = rand()%26 + 97;
        sprintf(ret, "%s%c", ret, ch);   // strcat(result, &ch);
    }
    ret[_STRLEN-1] = '\0';

    return ret;
}


// 随机生成不等长字符串
char * generate_string2(){
    const int size = rand()%(_STRLEN-1)+2;
    char *ret = (char *)malloc(sizeof(char)*size);
    char ch = '\0';
    
    for (int i=0; i<size; i++){
        ch = rand()%26+97;
        sprintf(ret, "%s%c", ret, ch);
    }
    ret[size-1] = '\0';

    return ret;
}