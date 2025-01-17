#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int abscompare(int a, int b)
{
    if (abs(a) > abs(b))
        return 1;
    else
        return -1;
}

void bubblesort(int *a, int n, int (*abcompare)(int, int))
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
        {
            if (abscompare(a[j], a[j + 1]) > 0)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
}

void main()
{
    int a[] = {-1, -78, 45, -23, 32};
    bubblesort(a, 5, abscompare);
    for(int i=0;i<5;i++) printf("%d ",a[i]);
}