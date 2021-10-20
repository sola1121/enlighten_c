# include "stdio.h"
# include "string.h"


int main(){

    char * words = "hello, world.";

    for (int i=0; i<strlen(words); i++)
         ungetc(words[i], stdin);   // 使用ungetc将字符依次放入输入流中

    for (int i=0; i<strlen(words); i++)
        putchar(getchar());   // 从输入流中读取, 这时会由最后放入的字符开始读取

    putchar('\n');

    return 0;
}