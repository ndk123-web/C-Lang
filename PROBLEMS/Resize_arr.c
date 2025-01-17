#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resize(int **arr, int size)
{
    int *t = (int *)realloc(*arr, sizeof(int) * size); // realloc(pointer,sizeof(int)*size)
    if (t == NULL)
    {
        printf("memory not allocated");
    }
    *arr = t;
}

int main()
{
    int n;
    printf("Enter Original Size");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    printf("\nOriginal Array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int newsize;
    printf("Enter new size");
    scanf("%d", &newsize);

    resize(&arr, newsize);

    if (newsize > n)
    {
        for (int i = n; i < newsize; i++)
        {
            arr[i] = i + 1;
        }
    }

    printf("New Array\n");
    for (int i = 0; i < newsize; i++)
    {
        printf("%d ", arr[i]);
    }
}

/*If realloc can extend the current block:

t and *arr will point to the same memory address.
The original block is simply resized, and no new memory allocation is needed.
If realloc cannot extend the current block:

realloc will allocate a new memory block with the requested size.
It will copy the contents of the original block to the new block.
It will free the original block.
t will point to this new block.
The pointer *arr is updated to point to the new block.
This behavior ensures that the data is preserved while resizing the array and 
that you efficiently manage memory without leaks. */