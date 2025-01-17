#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr;
    ptr = fopen("newFile.txt", "w");
    if (ptr == NULL)
    {
        fprintf(stderr,"Error attempts\n");  
        return 1;
    }

    int a, b, c;
    printf("Enter a and b\n");
    scanf("%d %d", &a, &b );        //"%d %d" space ny hona chiye ny to print ny hoga (No trailing Space)

    c = a + b;
    fprintf(ptr, "Sums is %d", c);      
    fclose(ptr);                        
    return 0;
}