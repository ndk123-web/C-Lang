#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b)
{
    if (a > b)
        return -1;    //ispe depend krega ab incr or dcr order
    else
        return 1;
}

void bubblesort(int *a, int n, int (*compare)(int, int))
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
        {
            if (compare(a[j], a[j + 1]) > 0)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
}

void main()
{
    int a[] = {2, 6, 4, 1, 8};
    bubblesort(a, 5, compare);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
}