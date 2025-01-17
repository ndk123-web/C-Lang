#include<stdio.h>
#include<stdlib.h>
#include<string.h>
                        
                            
void reversestr(char a[],int st,int end){           //  hello world => dlroW olleH
    if(st>=end){
        return;
    }else{
        char temp=a[st];
        a[st]=a[end];
        a[end]=temp;
        reversestr(a,st+1,end-1);
    }
}

int main()
{
    char a[]="hello Bhai";
    int len=strlen(a);
    printf("Before %s\n",a);
    reversestr(a,0,len-1);
    printf("After %s\n",a);
    return 0;
}