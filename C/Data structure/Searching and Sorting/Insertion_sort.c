
                                        //INSERTION SORT
#include<stdio.h>
int count=0;
main()
{
    int i,j,n;
    printf("\nEnter size of array to be sorted: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("\nArray elements without applying Insertion sort: ");
    for(i=0;i<n;printf("%d ",array[i]),i++);
    printf("\n\nArray elements after applying Insertion sort: ");
    int key;
    for(i=1;i<n;i++)
    {
        key=array[i];
        j=i-1;
        count++;
        while(j>=0 && array[j]>key)
        {
            array[j+1]=array[j];
            j--;
            count++;
        }
        array[j+1]=key;
    }
    for(i=0;i<n;printf("%d ",array[i]),i++);
    printf("\nTotal number of comparison=%d",count);
    printf("\n");
    return 0;
}
