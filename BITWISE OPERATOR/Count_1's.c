#include<stdio.h>
#include<stdlib.h>

int count(int n){
    int c=0;
    while(n!=0){
        c=c+(n&1);
        n=n>>1;
    }
    return c;
}

int main()
{
    int n;
    printf("Enter Number to Count no. if 1's\n");
    scanf("%d",&n);
    printf("Count :  %d ",count(n));
    return 0;
}