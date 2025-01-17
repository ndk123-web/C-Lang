#include<stdio.h>

int sum(int d,int n,int s){
    s=s+d;
    if(n==0) return s;
    else return sum(n%10,n/10,s);
}

void main()
{
    int n=12345;
    printf("%d",sum(0,n,0));
}