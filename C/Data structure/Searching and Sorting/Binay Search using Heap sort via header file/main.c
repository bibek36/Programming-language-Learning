
                                    //Binary sort
#include<stdio.h>
#include<stdlib.h>
#include"heap_sort.h"

int binary_iterative(int *arr,int n,int key)
{
    int low=0,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==*(arr+mid))
            return mid+1;
        else if(key<*(arr+mid))
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}

int binary_Recursive(int *arr,int low,int high,int key)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
            return mid+1;
        else if(key<arr[mid])
            return binary_Recursive(arr,low,mid-1,key);
        else
            binary_Recursive(arr,mid+1,high,key);
    }
    else
        return 0;
}

int main()
{
        int n,i;
        printf("\nEnter Number of elements: ");
        scanf("%d",&n);
        int *arr;
        arr=(int *)calloc(n,sizeof(int));
        printf("\nEnter array elements: ");
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        Build_Heap(arr,n);

        printf("\nThe Shorted Array is: \n");
        for(i=0;i<n;i++)
            printf("%d ",*(arr+i));
        printf("\n\nTotal Number of comparison: %d ",count);
        printf("\n\n");
        int key,x,choice;
        printf("\nEnter element you want to search: ");
        scanf("%d",&key);
        do
        {
            printf("Enter choice:\n1.Iterative\n2.Recursive\n3.exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: x=binary_iterative(arr,n-1,key);
                        if(x)
                            printf("\nSearched element %d is in position %d in array\n",key,x);
                        else
                            printf("\nElement not found\n");
                        break;
                case 2: x=binary_Recursive(arr,0,n-1,key);
                        printf("\n%d",x);
                        if(x)
                            printf("\nSearched element %d is in position %d in array\n",key,x);
                        else
                            printf("\nElement not found\n");
                        break;
                case 3: free(arr);
                        return 0;
                default: printf("\nInvalid input\n");
            }

            printf("\nEnter element you want to search: ");
            scanf("%d",&key);
        }while(1);
        free(arr);
        return 0;
}
