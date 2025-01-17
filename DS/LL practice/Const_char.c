#include<stdio.h>
#include<stdlib.h>

void print(char *c){            
    c[1]='A';                   //const char *c only use to read string not to modify
    while(*c!='\0'){
        printf("%c",*c);
        c++;
    }
}

void main()
{
    char c[20]="Hello"; //string stored as a compile time constant
    print(c);           //char c[20] stored in space array 
}