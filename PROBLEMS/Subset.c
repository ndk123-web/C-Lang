//Problem Statement: Given a set of positive numbers, find if there exists a subset whose sum is equal to a given number sum.

//Input: An array of positive integers and an integer sum.

//Output: "Yes" if there is a subset with the given sum, "No" otherwise.


#include<stdio.h>
#include<string.h>

int check(int *a,int ele,int len){
    int currentsum;
    for(int i=0;i<=len;i++){
        currentsum=a[i];                          //1 2 3 (3) -> o/p Yes
        
        if(currentsum==ele){
            return 1;
        }

        for(int j=i+1;j<=len;j++){
            currentsum=currentsum+a[j];
            if(currentsum==ele){
                return 1;
            }else if(currentsum>ele){
                break;
            }
        }
    }
    return 0;
}

int main()
{
    int a[]={1,2,3,4};
    int x;
    int len=sizeof(a)/sizeof(a[0]);
    printf("Enter Element to search Subset ");
    scanf("%d",&x);
    if(check(a,x,len-1)){
        printf("yeah Boyy!!\n");
    }else{
        printf("No Boyyy!!\n");
    }
    return 0;
}