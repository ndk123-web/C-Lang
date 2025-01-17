#include <stdio.h>

int sum(int a[], int size)    // a[]==*a (Array ka first address store krega)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += *(a+i);  //a[i]==*(a+i)
    }
    return s;
}

void main()
{
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    printf("Elements in array  %d", size);
    printf("\nSums %d", sum(a, size));
}