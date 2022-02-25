# include "stdio.h"
# include "stdlib.h"


_Noreturn sum(int x, int y){
    printf("%d + %d = %d\n", x, y, x+y);
    exit(0);
}


int main(){
    sum(1, 3);
}