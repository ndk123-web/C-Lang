#include <stdio.h>
#include <stdlib.h>

int *mergearray(int *a1, int *a2, int l1, int l2)
{
    int *result = (int *)malloc((l1 + l2) * sizeof(int));
    int i = 0, j = 0, c = 0;
    while (i < l1)
    {
        result[c++] = a1[i++];
    }
    while (j < l2)
    {
        result[c++] = a2[j++];
    }
    return result;
}

int main()
{
    int a1[] = {1, 2, 3, 4};
    int a2[] = {5, 6, 7, 8};
    int len1 = sizeof(a1) / sizeof(a1[0]);
    int len2 = sizeof(a2) / sizeof(a2[0]);
    int totallen = len1 + len2;
    int *merged = mergearray(a1, a2, len1, len2);
    for (int i = 0; i < totallen; i++)
    {
        printf("%d ", merged[i]);
    }
    return 0;
}