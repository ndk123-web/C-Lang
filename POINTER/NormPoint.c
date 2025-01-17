#include<stdio.h>

void main(){
    int *p;
    int a=5;
    p=&a;

    printf("%d\n",a);          
    printf("%d\n",&a);            
    printf("%d\n",p);
    
    printf("%d\n",*p);

    printf("%d\n",++(*p));
}