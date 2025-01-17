#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b)
{
    const char *A = *(const char **)a;
    const char *B = *(const char **)b;
    return strcmp(A, B);
}

void main()
{
    const char *ch[] = {"ndk", "behen", "op"};
    int n=sizeof(ch)/sizeof(ch[0]);
    qsort(ch, n, sizeof(const char *), compare);
    printf("\n %d \n",n);
    for (int i = 0; i < n; i++)
        printf("%s ", ch[i]);
}