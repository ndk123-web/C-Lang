#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c;
    FILE *ptr;
    ptr=fopen("test.txt","w");
    
    if(ptr==NULL) {
        printf("Error opening file");
        return 1;
    }

    printf("Enter 2 numbers");
    scanf("%d %d",&a,&b);
    c=a+b;
    fprintf(ptr,"The Sum is %d",c);
    fclose(ptr);
    return 0;
}