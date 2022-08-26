#include<stdio.h>
void PrintArray(int [],int);                                    //(Array,size)
void MergeSort(int [],int,int);                                 //(Array,low,high)
void Merge(int [],int,int,int);                                 //(Array,low,mid,high)
int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int A[n];
    int i=0;
    printf("\nEnter Array elements: ");
    for(;i<n;scanf("%d",&A[i]),i++);

    printf("\nOriginal Array: ");
    PrintArray(A,n);

    printf("\nSorted Array: ");
    MergeSort(A,0,n-1);

    printf("----------------------\n");
    PrintArray(A,n);
    printf("\n----------------------\n");
    return 0;
}


void PrintArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}

void MergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

void Merge(int A[],int l,int m,int h)
{
    int i,j,k;
    int size=h-l+1;
    int B[size];
    i=l,j=m+1,k=0;
    while(i<=m && j<=h)
    {
        if(A[i]<=A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }

    for(;i<=m;i++)
        B[k++]=A[i];

    for(;j<=h;j++)
        B[k++]=A[j];

    printf("\n");
    PrintArray(B,size);
    printf("\n");

    for(i=0;i<size;i++)
    {
        A[l++]=B[i];
    }
}

