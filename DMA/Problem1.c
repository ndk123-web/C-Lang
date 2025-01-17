#include<stdio.h>
#include<stdlib.h>

void pwh(){
    printf("Hello World\n");
}

int* add(int *a,int *b){
    int *z;
    z=(int*) malloc(sizeof(int ));                      //because stack ne pahile hee deallcate krdiya hai &z ko isiliye ans hee ny arrha
    *z=(*a)+(*b);                //agar heap mein jagah diya toh wo deallocate ny hoga unless humne free fn use kiya ho
    return (z);
}

void main()
{
    int a=10,b=20;
    int *ptr=add(&a,&b);
    pwh();
    printf("Sums %d",*ptr);
}