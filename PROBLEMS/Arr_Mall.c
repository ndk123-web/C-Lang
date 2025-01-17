#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter Size: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int)); // Correct typecasting of malloc return

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Addresses:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        printf("%p  ", (void *)&arr[i]); // Print addresses using %p correctly
    } //%p format specifier expects (void*) arguement
    printf("\n");

    printf("Printing Values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d     ", arr[i]); // Print array values using %d for integers
    }
    printf("\n");

    free(arr);
    return 0;
}
