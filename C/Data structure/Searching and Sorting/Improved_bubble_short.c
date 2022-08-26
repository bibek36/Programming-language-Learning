
                                //IMPROVED BUBBLE SORT
#include<stdio.h>
int count=0;
int main()
{
    int i,j,n,t,temp,bound;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int Array[n];
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&Array[i]);

    printf("\nArray elements without applying Improved bubble sort are: ");
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nArray elements after applying Improved bubble sort are:  ");

    bound=0;
    do{
            t=n-1;
            for(j=n-1;j>bound;j--)
            {
                count++;
                if(Array[j]<Array[j-1])
                {
                    temp=Array[j];
                    Array[j]=Array[j-1];
                    Array[j-1]=temp;
                    t=j;
                }
            }
            bound=t;
        }while(t<n-1);
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nTotal number of Comparison in Improved bubble sort for n=%d elements is: %d",n,count);
    printf("\n\n");
    return 0;
}
