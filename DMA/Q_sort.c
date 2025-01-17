#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int A = *((int *)a);
    int B = *((int *)b);
    return abs(A) - abs(B);
}

void main()
{
    int a[] = {-1, 5, -3, 44, 12};
    qsort(a, 5,sizeof(int),compare);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
}