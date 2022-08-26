# include<stdio.h>
# include<stdlib.h>
int main()
{
    int n;
    printf("\nEnter how many integers you want to allocate: ");
    scanf("%d",&n);
    int *ptr;
    ptr=(int*) malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("\nUnable to allocate memory\nExecuting from the program");
        exit(1);
    }
    int i;
    printf("\n------------------------By default value for malloc is:----------------------- \n");
    printf("\nThe content of the array is: ");
    for(i=0;i<n;i++)
        printf("%d ",*(ptr+i));
    printf("\n\n------------------------Enter elements:---------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d: ",i+1);
        scanf("%d",ptr+i);
    }

    printf("\nThe content of the array is: ");
    for(i=0;i<n;i++)
        printf("%d ",*(ptr+i));
    printf("\n\n");
    free(ptr);
    return 0;
}
