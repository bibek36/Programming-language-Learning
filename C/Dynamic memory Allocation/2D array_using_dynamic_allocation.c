#include<stdio.h>
#include<stdlib.h>
int **allocate(int row,int col)
{
    int **p;
    p=(int **)malloc(row*sizeof(int *));
    if(p==NULL)
    {
        printf("\nUnable to allocate memory.\nExiting the program\n");
        exit(0);
    }
    int i;
    for(i=0;i<row;i++)
    {
        *(p+i)=(int *)malloc(col*sizeof(int));
       /* if(*(p+i)==NULL)
        {
            printf("\nUnable to allocate memory.\nExiting the program\n");
            exit(0);
        }   */
    }
    return p;
}

void insert(int **p,int row,int col)
{
    int i,j;
    printf("\n\n---------------Enter array elements----------------------\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("\nEnter element [%d][%d]: ",i,j);
            scanf("%d",(*(p+i)+j));
        }
    }
}

void display(int **p,int row,int col)
{
    int i,j;
    printf("\n\n---------------Array elements are:----------------------\n\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%4d ",*(*(p+i)+j));
        }
        printf("\n");
    }
}

void deallocate(int **p,int row,int col)
{
    int i;
    for(i=0;i<row;i++)
    {
        free(p+i);
    }
    free(p);
}

int main()
{
        int row,col;
        int **ptr;
        printf("\nEnter number of Rows: ");
        scanf("%d",&row);
        printf("\nEnter number of Columns: ");
        scanf("%d",&col);

        ptr=allocate(row,col);
        insert(ptr,row,col);
        display(ptr,row,col);
        deallocate(ptr,row,col);

        return 0;
}
