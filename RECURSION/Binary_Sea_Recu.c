#include <stdio.h>

int binarysearch(int a[], int low, int high, int x)
{
    int mid;
    mid = low + (high - low) / 2;

    if (a[mid] == x)
    {
        return mid;
    }
    else if (a[mid] < x)
    {
        return binarysearch(a, mid + 1, high, x);
    }
    else
    {
        return binarysearch(a, low, mid - 1, x);
    }
    return -1;
}
int main()
{
    int a[] = {33, 54, 76, 79, 100};
    int x = 100;
    int low = 0;
    int high = sizeof(a) / sizeof(a[0]);
    int result = binarysearch(a, low, high - 1, x);

    if (result == -1)
        printf("Element Not Found!\n");
    else
        printf("Element at Index %d ", result + 1);
    return 0;
}