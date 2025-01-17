#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[] = "abc";
    char b[] = "op";
    int l1 = strlen(a);
    int l2 = strlen(b);
    int totall = l1 + l2;
    int c = 0, i = 0;
    char *merge = (char *)malloc(totall + 1 * sizeof(char));

    while (i < l1 && i < l2)
    {
        merge[c++] = a[i];
        merge[c++] = b[i];
        i++;
    }
    while (i < l1)
    {
        merge[c++] = a[i++];
    }
    while (i < l2)
    {
        merge[c++] = b[i++];
    }
    printf("\n %s ", merge);
}