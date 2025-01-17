#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
    int hash[size]={0};
    int loc,x,ch,key,i;

    while(1)
    {
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&key);
                    i=1;
                    loc=key%size;
                    while(hash[loc]!=0)
                    {
                        loc=(key%size+i)%size;
                        i++;

                        if(i==size)
                        {
                            printf("Hash Full\n");
                            break;
                        }    
                    }
                    if(hash[loc]==0)
                    {
                        hash[loc]=key;
                        printf("Inserted at %d\n",loc);
                    }
                    break;
                    
            case 2: printf("Enter to be searched element");
                    scanf("%d",&x);
                    int j=1;
                    loc=x%size;
                    while(hash[loc]!=x)
                    {
                        loc=(x%size+j)%size;
                        j++;
                        
                        if(j==size)
                        {
                            printf("Element not found\n");
                            break;
                        }
                    }
                    if(hash[loc]==x)
                    printf("Element Found\n");
                    printf("Found in location %d",loc);
                    break;
                    
            default: printf("Invalid choice");
                     break;
                    
        }
    }
}