# include "stdio.h"
# include "stdlib.h"

# define LEN 10


int main(){

    int * array = (int*) malloc(sizeof(int)*LEN), 
        * temp = array;

    ++array;

    free(temp);
    
    return 0;
}