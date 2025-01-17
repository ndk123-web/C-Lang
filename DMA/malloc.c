#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p;
    p = (int *)malloc(sizeof(int));
    *p = 10;
    printf("%d\n", *p);
    printf("%p\n", &p);
    printf("%p\n\n", p);

    free(p);

    p = (int *)malloc(5 * sizeof(int));
    int c = 1;
    for (int i = 0; i < 5; i++)
    {
        p[i] = c++;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *p++);
    }
}