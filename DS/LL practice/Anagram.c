/* Program For Run O(n) time anagram program of String  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int check[128] = {0};
    int i = 0, f = 1;
    char a[] = "ndkn";
    char b[] = "kdnn";
    int l1 = strlen(a);
    int l2 = strlen(b);

    if (l1 != l2)
    {
        f = 0;
    }
    while (a[i] != '\0' && b[i] != '\0')
    {
        check[a[i]]++;
        check[b[i]]--;
        f = 1;
        i++;
    }
    i = 0;
    while (i < 128)
    {
        if (check[i] != 0)
        {
            f = 0;
            break;
        }
        else
        {
            f = 1;
            i++;
        }
    }
    if (f)
        printf("Anagram");
    else
        printf("Not Anagram");
    return 0;
}