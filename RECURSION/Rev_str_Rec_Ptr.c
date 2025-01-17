#include <stdio.h>
#include <string.h>

char *reversestr(char *c, int st, int end)
{
    if (st >= end)
    {
        return c;
    }
    else
    {
        char t = c[st];
        c[st] = c[end];
        c[end] = t;
        return reversestr(c, st + 1, end - 1);
    }
}

int main()
{
    char ch[] = "Hello Bhai";
    int len = strlen(ch);
    char *result = reversestr(ch, 0, len - 1);
    printf("Reverse String \n%s", result);
}