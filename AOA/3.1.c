#include <stdio.h>
#include<stdlib.h>
int min,max;

void minMax(int arr[],int first,int last){
    int mid,max1,min1;
    if(first==last){
        max=arr[first];
        min=arr[first];
    }
    else if(first==last-1){
        if(arr[first]>arr[last]){
            max=arr[first];
            min=arr[last];
        }else{
            max=arr[last];
            min=arr[first];
        }
    }else{
        mid=(first+last)/2;
        minMax(arr,first,mid);
        max1=max;
        min1=min;
        minMax(arr,mid+1,last);
        if(max<max1){
            max=max1;
        }
        if(min>min1){
            min=min1;
        }
    }
}
int main()
{
    int n,i;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("The random array is : ");
    for(i=0;i<n;i++){
        arr[i]=rand()%1000+1;
        printf("%d ",arr[i]);
    }

    min=arr[0];
    max=arr[0];
    minMax(arr,0,n-1);
    printf("\n");
    
    printf("Max= %d \nMin=%d\n",max,min);

    return 0;
}