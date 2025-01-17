#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
    int hash[size]={0};
    int key,x,ch,loc;
    int i,j;

    while(1)
    {
        printf("Enter Choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter Element");
                    scanf("%d",&key);
                    i=1;
                    loc=key%size;
                    while(hash[loc]!=0){
                        loc=(key%size+i)%size;
                        i++;

                        if(i==size){
                            printf("Hash Full\n");
                        }
                    }
                    if(hash[loc]==0)
                    {
                        hash[loc]=key;
                        printf("Inserted at %d\n",loc);
                    }
                    break;

            case 2: printf("To be searched Element");
                    scanf("%d",&x);
                    loc=x%size;
                    j=1;
                    while(hash[loc]!=x){
                        loc=(x%size + j)%size;
                        j++;

                        if(j==size){
                        printf("Hash Full\n");
                        }
                    }
                    if(hash[loc]==x){
                        printf("Its present on %d\n",loc);
                    }
                    else
                    printf("Its not present \n");
                    break;

            default: printf("Invalid choice\n");
                    break;
        }
    }
}