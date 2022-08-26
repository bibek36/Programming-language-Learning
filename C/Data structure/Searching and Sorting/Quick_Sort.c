                                    //QUICK SORT

#include<stdio.h>
#include<stdlib.h>
int count=0;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int *arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j;
    for(j=low;j<=high-1;j++)
    {
        count++;
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr+i,arr+j);
        }
    }
    swap(arr+(i+1),arr+high);
    return i+1;
}
void quicksort(int *arr,int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main()
{
    int n,i,*arr;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    arr=(int *)calloc(n,sizeof(int));
    printf("Enter array elements: ");
    for(i=0;i<n;scanf("%d",arr+i),i++);

    quicksort(arr,0,n-1);
    printf("\nSorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n\nTotal number of comparison: %d",count);
    printf("\n\n");
    return 0;
}
