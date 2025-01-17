#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    char A = (*(char *)a);
    char B = (*(char *)b);
    return A - B;
}
void main()
{
    char ch[] = {'A', 'a', 'Z', 'b', 'h', '\0'};
    qsort(ch, 5, sizeof(char), compare);
    for (int i = 0; i < 5; i++)
        printf("%c ", ch[i]);
}