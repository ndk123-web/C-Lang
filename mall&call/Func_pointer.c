#include<stdio.h>

int add(int a,int b){
    return (a+b);
}

void pwh(char *c){
    printf("Hello %s\n",c);
}

void main()
{
    int c;
    int (*p)(int,int); //declaration of Fn Pointer
    p=add;             //assigning address of base of add Fn to ptr p 
    c=p(2,3);          //calling to add Fn 
    
    void (*q)(char*);
    q=pwh;
    q("Ndk");
    printf("%d",c);
}