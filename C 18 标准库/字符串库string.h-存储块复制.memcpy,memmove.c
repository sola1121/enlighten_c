# include "stdio.h"
# include "string.h"

# define LEN 14


void show(int array[], int len){
    for (int i=0; i<len; i++)
        printf("%-3d", array[i]);
    putchar('\n');
}


int main(){
    char s1[LEN] = "Hello, world.";
    char s2[LEN] = {'\0'};

    puts("使用memcpy进行复制字符串.");

    // 对于字符串, 使用memcpy复制
    memcpy(s2, s1, LEN);
    printf("s1 = %s\ns2 = %s\n", s1, s2);
    
    puts("重设值. 使用memmove进行复制字符串.");
    memset(s2, '\0', LEN);

    // 对于字符串, 使用memmove复制
    memmove(s2, s1, LEN);
    printf("s1 = %s\ns2 = %s\n", s1, s2);
    
    puts("重设值. 使用strncpy进行复制字符串.");
    memset(s2, '\0', LEN);

    // 对于字符串, 使用strncpy复制
    strncpy(s2, s1, LEN);
    printf("s1 = %s\ns2 = %s\n", s1, s2);

    int arr1[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int arr2[LEN] = {0};

    puts("使用memcpy进行复制int数组.");

    // 注意, 对数组而言, 字节数一般与元素个数不同, 如果要拷贝数组, 要使用sizeof(类型)*长度

    // 对于int数组, 使用memcpy复制
    memcpy(arr2, arr1, sizeof(int)*LEN);
    show(arr2, LEN);

    puts("重设值. 使用memmove进行复制int数组.");
    memset(arr2, 0, sizeof(int)*LEN);

    // 对于int数组, 使用memmove复制
    memmove(arr2, arr1, sizeof(int)*LEN);
    show(arr2, LEN);

    return 0;
}