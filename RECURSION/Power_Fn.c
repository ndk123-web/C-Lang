#include <stdio.h>

int power(int x, int y)
{
    if (y == 0)
        return 1;
    else
        return x * power(x, y - 1);
}

void main()
{
    int x = 3;
    int y = 2;
    printf("%d", power(x, y));
}