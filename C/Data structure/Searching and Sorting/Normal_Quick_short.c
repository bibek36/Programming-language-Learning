#include<stdio.h>
void Quick_short(int [],int ,int);
int Partition(int [],int ,int);
int main()
{
    int i,j,n;
    printf("\nEnter size of array to be shorted: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter element of array: ");
    for(i=0;i<n;scanf("%d",&array[i]),i++);
    printf("\n\nArray before using Quick short: ");
    for(i=0;i<n;printf("%d ",array[i]),i++);
    Quick_short(array,0,n-1);
    printf("\n\nArray After using Quick short: ");
    for(i=0;i<n;printf("%d ",array[i]),i++);
    return 0;
}

void Quick_short(int array[],int p,int r)
{
    int q,i;
    const int n=r;
    if(p<r)
    {
        q=Partition(array,p,r);
        printf("\nq=%d , Elements: ",q);
        for(i=0;i<=n;printf("%d ",array[i]),i++);
        if(q-p>r-q+1)
        {
            Quick_short(array,q+1,r);
            Quick_short(array,p,q-1);
        }
        else
        {
            Quick_short(array,p,q-1);
            Quick_short(array,q+1,r);
        }
    }
}

int Partition(int array[],int p,int r)
{
    int x=array[r];
    int i=p-1,j,temp;
    for(j=p;j<r-1;j++)
    {
        if(array[j]<=x)
        {
            i++;
            temp=array[j];
            array[j]=array[i];
            array[i]=temp;
        }
    }
    temp=array[i+1];
    array[i+1]=array[r];
    array[r]=temp;

    return i+1;
}
