#include<stdio.h>

int main()
{
    int i,j,key;
    int arr[]={ 5,3,4,1,2};

    for(i=1;i<5;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j] > key  ){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}