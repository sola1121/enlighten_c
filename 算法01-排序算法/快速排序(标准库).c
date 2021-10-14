# include "stdio.h"
# include "stdlib.h"


/*
标准库stdlib.h 中提供的快速查找算法
void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));

base
    Pointer to the first object of the array to be sorted, converted to a void*.

num
    Number of elements in the array pointed to by base.
    size_t is an unsigned integral type.

size
    Size in bytes of each element in the array.
    size_t is an unsigned integral type.

compar
    Pointer to a function that compares two elements.
    This function is called repeatedly by qsort to compare two elements.
    
    原型为
        int compar (const void* p1, const void* p2);

*/


int values[] = { 40, 10, 100, 90, 20, 25 };


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main ()
{
    int n;

    qsort(values, 6, sizeof(int), compare);

    for (n=0; n<6; n++)
        printf("%d ",values[n]);

    putchar('\n');
    return 0;
}