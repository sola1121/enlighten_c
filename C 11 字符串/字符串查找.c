# include "stdio.h"
# include "string.h"


int main(){
    char str1[] = "hello, world.";
    
    char str2[] = "hi, world.";

    printf("%s\n", strpbrk(str1, str2));
    printf("%p\n", strpbrk(str1, "无"));

    printf("%s\n", strstr(str1, "ll"));
    printf("%p\n", strstr(str1, "无"));

    return 0;
}