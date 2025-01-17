#include<stdio.h>

int main()
{
    int i,j;
    int arr[]={5,3,7,6,4};

    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            if(arr[j] >= arr[j+1] ){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    for(i=0;i<5;i++)
    printf("%d ",arr[i]);
}