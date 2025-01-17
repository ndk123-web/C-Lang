#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    int *arr;
    printf("Enter how many Elements you want\n");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter Elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    printf("Location of &arr[0] %d\n",&arr[0]);
    printf("Location of arr %d\n",arr);
    printf("Data at arr[0] %d\n" ,arr[0]);
    printf("Data at arr %d\n",*arr);
    
    free(arr);
    arr=NULL;
}