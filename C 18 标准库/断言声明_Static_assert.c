# include "stdio.h"
# include "limits.h"

// CHAR_BIT 应该为8

_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed.");

int main(){
    puts("char 是 16bits的.");
    return 0;
}