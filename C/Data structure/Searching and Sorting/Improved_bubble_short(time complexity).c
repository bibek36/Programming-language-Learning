#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int i,j,n,t,temp,choice,bound;
    time_t start,end;
    srand(time(NULL));
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int Array[n];
    printf("\nTime complexity of Improved bubble short for-\n1.Enter your own elements.\n2.Find time complexity for Worst case.\n3.Choose Random numbers.\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nEnter array elements: ");
                for(i=0;i<n;i++)
                scanf("%d",&Array[i]);
                break;

        case 2: for(i=0,j=n;i<n;Array[i]=j--,i++);
                break;
        case 3: for(i=0;i<n;Array[i]=rand()%1000,i++);
                break;
        default: printf("\nInvalid Input");
                 return 0;
    }
    printf("\nArray elements without using Improved bubble short are:\n");
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nArray elements after using Improved bubble short are:\n ");
    start=clock();
    int pass=0;
    bound=0;
    do{
            t=n-1;
            for(j=n-1;j>bound;j--)
            {
                if(Array[j]<Array[j-1])
                {
                    temp=Array[j];
                    Array[j]=Array[j-1];
                    Array[j-1]=temp;
                    t=j;
                }
            }
            bound=t;
            pass++;
        }while(t<n-1);
    /*
    bound=n;
    do{
            t=0;
            for(i=0;i<=bound-1;i++)
            {
                if(Array[i]>Array[i+1])
                    {
                        temp=Array[i];
                        Array[i]=Array[i+1];
                        Array[i+1]=temp;
                        t=i;
                    }
            }
            bound=t;
            pass++;
        }while(t>0);
    */
    end=clock();
    for(i=0;i<n;i++)
        printf("%d ",Array[i]);
    printf("\n\nTotal number of Passes in Improved bubble short for n=%d elements is: %d",n,pass);
    printf("\nTime taken for Improved bubble short= %.2f sec ",(float)(end-start)/CLOCKS_PER_SEC);
    printf("\nbound=%d",bound);
    printf("\n\n");
    return 0;
}
