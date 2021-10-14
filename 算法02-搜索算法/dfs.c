# include "stdio.h"
# include "stdbool.h"

# define len 10

/*
    深度优先的
*/

int array[len], num; 

bool sign[len];


void dsf(int step){
    int i;

    if (step==num+1){
        for (i=1; i<=num; i++)
            printf("%d", array[i]);
        putchar('\n');

        return;
    }

    for (i=1; i<=num; i++){
        if (sign[i]==false) {
            array[step] = i;
            sign[i] = true;

            dsf(step+1);
            sign[i] = false;
        }
    }

    return;
}


int main(){
    num = 4;

    dsf(1);


    return 0;
}