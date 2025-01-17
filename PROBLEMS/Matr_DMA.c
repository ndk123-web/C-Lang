#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c;
    printf("Enter Row and Column");
    scanf("%d %d", &r, &c);

    int **array = (int **)malloc(sizeof(int *) * r);

    for (int i = 0; i < r; i++)
    {
        array[i] = malloc(sizeof(int) * c);
    }
    printf("Enter Elements");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("Printing\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
    free(array);
    return 0;
}