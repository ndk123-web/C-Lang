#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int A = *((int *)a);        //dereference a 
    int B = *((int *)b);        //dereference b
    return abs(A) - abs(B);     //const void * is generic ptr which points to any data type     
}

void main()
{
    int a[] = {-1, 5, -3, 44, 12};
    qsort(a, 5,sizeof(int),compare);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
}