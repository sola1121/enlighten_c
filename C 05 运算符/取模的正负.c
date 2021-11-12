# include "stdio.h"


int main(){

    // 被取模数正负决定余数正负

    printf("%d %% %d = %d\n", 32, 3, 32%3);
    printf("%d %% %d = %d\n", -32, 3, -32%3);
    printf("%d %% %d = %d\n", 32, -3, 32%-3);
    printf("%d %% %d = %d\n", -32, -3, -32%-3);


    return 0;
}