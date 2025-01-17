#include<stdio.h>
#include<stdlib.h>

int main(){
    int l=0;
    printf("Enter Lenght");
    scanf("%d",&l);

    int *arr=malloc(sizeof(int)*l);

    for(int i=0;i<l;i++)
    scanf("%d",&arr[i]);

    for(int i=0;i<l;i++)
    printf("%d ",arr[i]);

    free(arr);
    return 0;
}