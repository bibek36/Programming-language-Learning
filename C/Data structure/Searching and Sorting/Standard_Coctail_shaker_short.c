#include<stdio.h>
#include<time.h>
int main()
{
    int i,n,j,temp,choice;
    time_t start,end;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int Array[n];
    printf("\nTime complexity of Cocktail shaker short for-\n1.Enter your own elements.\n2.Find time complexity for Worst case.\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nEnter array elements: ");
                for(i=0;i<n;i++)
                scanf("%d",&Array[i]);
                break;

        case 2: for(i=0,j=n;i<n;Array[i]=j--,i++);
                break;
        default: printf("\nInvalid Input");
                 return 0;
    }
    printf("\nArray elements without using Cocktail shaker short are:\n");
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nArray elements after using Cocktail shaker short are:\n ");
    start=clock();
    int pass=0;
    int t=0;
    do
    {
        if(t%2==0)
        for(j=0;j<n-1-t;j++)
        {
            if(Array[j]>Array[j+1])
                {
                    temp=Array[j];
                    Array[j]=Array[j+1];
                    Array[j+1]=temp;
                }
        }
        else
        for(j=n-1;j>t;j--)
        {
            if(Array[j]<Array[j-1])
                {
                    temp=Array[j];
                    Array[j]=Array[j-1];
                    Array[j-1]=temp;
                }
        }
        t++;
        pass++;
    }while(t<2*(n-1));
    end=clock();
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nTotal number of Passes in Cocktail shaker short for n=%d elements is: %d",n,pass);
    printf("\nTime taken for Cocktail shaker short= %.2f sec ",(float)(end-start)/CLOCKS_PER_SEC);
    printf("\n\n");
    return 0;
}
