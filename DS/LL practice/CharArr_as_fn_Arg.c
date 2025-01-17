#include<stdio.h>
#include<string.h>

void print(char *c){       //*c mein c[] ka means h ka location hai
    while(*c!='\0'){
        printf("%c",*c);    
        c++;                //c++=c+1 whihc is c+sizeof(c)*i
    }
}     

void main()
{
    char c[]="Hello";
    printf("Size of Char Array %d\n",strlen(c));
    print(c);
}