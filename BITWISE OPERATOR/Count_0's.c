#include<stdio.h>
#include<stdlib.h>

int count(int n){
    int c=0;
    unsigned int size_of_bytes=sizeof(n)*8;
    unsigned int k=~n;
    for(int i=0;i<size_of_bytes;i++){
        if((k&1))
        c++;
        k=k>>1;
    }
    return size_of_bytes-c;
}

void main()
{
    int n;
    printf("Enter Number");
    scanf("%d",&n);

    printf("Count : %d",count(n));
}