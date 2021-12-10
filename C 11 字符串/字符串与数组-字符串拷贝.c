# include "stdio.h"
# include "malloc.h"


int main(){
    char array_1[] = {'h', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '.', '\0'},
        * array_2 = (char *) malloc(sizeof(array_1));

    int count = 0;
    char * pt = array_1;
    for (; *pt!='\0'; pt++, count++){
        array_2[count] = *pt;
    }
    array_2[count] = '\0';   // 记得末尾添加\0, 以将数组构成字符串


    pt = array_2;
    while (*pt!='\0'){
        putchar(*pt);
        pt++;
    }

    putchar('\n');
    free(array_2);

    return 0;
}