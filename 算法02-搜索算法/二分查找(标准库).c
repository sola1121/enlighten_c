# include "stdio.h"
# include "stdlib.h"

/*
标准库stdlib.h中提供的折半查找算法(二分查找)
void* bsearch (const void* key, const void* base,
               size_t num, size_t size,
               int (*compar)(const void*,const void*));

key
    Pointer to the object that serves as key for the search, type-casted to a void*.

base
    Pointer to the first object of the array where the search is performed, type-casted to a void*.

num
    Number of elements in the array pointed to by base.
    size_t is an unsigned integral type.

size
    Size in bytes of each element in the array.
    size_t is an unsigned integral type.

compar
    Pointer to a function that compares two elements.
    This function is called repeatedly by bsearch to compare key against individual elements in base. 

    原型为
        int compar (const void* pkey, const void* pelem);

*/

int compareints (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int values[] = { 50, 20, 60, 40, 10, 30 };

int main ()
{
    int * pItem;
    int key = 40;

    // 折半查找只能对有序数列进行查找, 所以这里使用快速排序将数组升序排列
    qsort (values, 6, sizeof (int), compareints);

    // 使用折半查找找到查找值位置
    pItem = (int*) bsearch(&key, values, 6, sizeof (int), compareints);

    if (pItem!=NULL)
        printf("%d is in the array.\n", *pItem);
    else
        printf("%d is not in the array.\n", key);

    return 0;
}