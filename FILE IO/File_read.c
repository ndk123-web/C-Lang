#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* ptr;
    char content[1000];
    ptr=fopen("test.txt","r");              // read kr rhe hai yaha
    if(ptr==NULL){
        printf("File Not Opens\n");
    }else{
       // printf("File Opens\n");
        fgets(content,1000,ptr);            //bas 1000 char ko read krne ke liye
        printf("%s",content);
           
    }
    if(ptr!=NULL){
        while(fgets(content,1000,ptr)){     //poora text ko read krne ke liye
            printf("%s",content);
        }
    }
    fclose(ptr);                            //isse close krne se permantly store hoga test file
    return 0;
}