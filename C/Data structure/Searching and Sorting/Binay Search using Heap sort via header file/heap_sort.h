
                                //Heap sort(As Header file)
#include<stdio.h>
#include<stdlib.h>
int count=0;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void Build_Heap(int *arr,int n)
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)
        Max_Heapify(arr,n,i);

    for(i=n-1;i>=0;i--)
    {
        swap(arr,arr+i);
        Max_Heapify(arr,i,0);
    }

    return;
}

void Max_Heapify(int *arr,int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest,temp;
    if(l<n && *(arr+i)<*(arr+l))
        {
            largest=l;
            count++;
        }
    else
        largest=i;
    if(r<n && *(arr+largest)<*(arr+r))
        {
            largest=r;
            count++;
        }
    if(largest!=i)
    {
        swap(arr+i,arr+largest);
        Max_Heapify(arr,n,largest);
    }
    return;
}
