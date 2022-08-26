#include<stdio.h>
#include<limits.h>
void swap(int *,int *);
void PrintArray(int [],int);                                    //(Array,size)
void QuickSort(int [],int ,int);                                //(Array,low,high)
int Partition(int [],int ,int);                                //(Array,low,high)
int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int A[n+1];
    int i=0;
    printf("\nEnter Array elements: ");
    for(;i<n;scanf("%d",&A[i]),i++);
    A[n]=INT_MAX;
    printf("\nOriginal Array: ");
    PrintArray(A,n);

    printf("\nSorted Array: ");
    QuickSort(A,0,n);

    printf("\n----------------------\n");
    PrintArray(A,n);
    printf("\n----------------------\n");
    return 0;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void PrintArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}

int Partition(int A[],int low,int high)
{
    int i,j,temp;
    i=low,j=high;
    int pivot=A[low];
    while(i<j)
    {
        do{
            i++;
        }while(A[i]<=pivot);

        do{
            j--;
        }while(A[j]>pivot);
        if(i<j)
            swap(&A[i],&A[j]);
    }
    swap(&A[j],&A[low]);
    return j;
}

void QuickSort(int A[],int low,int high)
{
    if(low<high)
    {
        int j=Partition(A,low,high);
        QuickSort(A,low,j);
        QuickSort(A,j+1,high);
    }
}


