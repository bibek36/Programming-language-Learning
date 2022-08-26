
                                    //COCKTAIL SHAKER SORT
#include<stdio.h>
int count=0;
int main()
{
    int i,n,j,temp,counter=0;
    time_t start,end;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int Array[n];
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&Array[i]);

    printf("\nArray elements without using Cocktail shaker short are:\n");
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nArray elements after using Cocktail shaker short are:\n ");
    start=clock();
    int t1=0,t2=0;
    do
    {
        counter=0;
        if(t1%2==0)
        {
            for(j=t1;j<n-t1-1;j++)
            {
                if(++count && Array[j]>Array[j+1])
                    {
                        temp=Array[j];
                        Array[j]=Array[j+1];
                        Array[j+1]=temp;
                        counter=1;
                    }
            }
            t1++;
        }
        else
        {
            for(j=n-t2-1;j>t2;j--)
            {
                if(++count && Array[j]<Array[j-1])
                    {
                        temp=Array[j];
                        Array[j]=Array[j-1];
                        Array[j-1]=temp;
                        counter=1;
                    }
            }
            t2++;
        }
        if(counter==0)
            break;
    }while(1);
    end=clock();
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nTotal number of comparison = %d",count);
    printf("\n\n");
    return 0;
}
