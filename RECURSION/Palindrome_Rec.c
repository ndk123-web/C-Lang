#include <stdio.h>
#include <string.h>

void reverse(char cc[], int st, int end)
{
    if (st >= end)
    {
        return;
    }
    else
    {
        char t = cc[st];
        cc[st] = cc[end];
        cc[end] = t;
        reverse(cc, st + 1, end - 1);
    }
}

int check(char c[], int len)
{
    char cc[20] = " ";
    strcpy(cc, c);
    reverse(cc, 0, len - 1);

    if (strcmp(c, cc) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char c[] = "nayan";
    int len = strlen(c);
    if (check(c, len))
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    return 0;
}