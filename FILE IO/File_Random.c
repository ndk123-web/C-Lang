#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    FILE *ptr;
    ptr = fopen("newFile.txt", "w");
    if(ptr==NULL){
        fprintf(stderr,"Error Attempts\n");
        return 1;
    }
    printf("100 no. from 1 to 20 randomly\n Check in newFile.txt\n");
    int c;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        c = rand() % 20 + 1;
        fprintf(ptr," %d\n ",c);
    }
    fclose(ptr);
    return 0;
}