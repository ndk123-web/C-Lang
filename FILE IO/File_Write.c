#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* ptr;
    ptr=fopen("newFile","w");       //newFile create hua automatic with write mode

    if(ptr!=NULL){
        fputs("Hello Bhai\n",ptr);
        fputs("I am NDK and its Text i am writing on to the newFile ",ptr);
    }
    fclose(ptr);
    return 0;
}