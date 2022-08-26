

                                    //INCOMPLETE(LOGICAL ERROR)


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
        *(p+i)=(int *)calloc(col,sizeof(int));
    }
    return p;
}

void insert(int **p,int row,int col)
{
    int i,j;
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

void arr_multiply(int **p1,int **p2,int **p3,int row1,int row2,int col1,int col2)
{
    int i,j,temp;
    for(i=0;i<row1;i++)
    {
        temp=0;
        for(j=0;j<col2;j++)
        {
            temp+=*(*(p1+i)+j) * *(*(p2+j)+i);
        }
        *(*(p3+i)+j)=temp;
        printf("\ntemp=%d, %d",temp,*(*(p3+i)+j));
    }
}

int main()
{
    int row1,col1,row2,col2;
    int **ptr1,**ptr2,**ptr3;
    printf("\nEnter number of Rows for 1st array: ");
    scanf("%d",&row1);
    printf("\nEnter number of Columns for 1st array: ");
    scanf("%d",&col1);
    printf("\nEnter number of Rows for 2nd array: ");
    scanf("%d",&row2);
    printf("\nEnter number of Columns for 2nd array: ");
    scanf("%d",&col2);

    if(col1!=row2)
    {
        printf("\nInvalid input of row and column for array multiplication\nExiting the program\n");
        exit(0);
    }

    ptr1=allocate(row1,col1);
    ptr2=allocate(row2,col2);
    ptr3=allocate(row1,col2);

    printf("\n\n---------------Enter 1st array elements----------------------\n");
    insert(ptr1,row1,col1);
    printf("\n\n---------------Enter 2nd array elements----------------------\n");
    insert(ptr2,row2,col2);

    printf("\n\n---------------1st Array elements are:----------------------\n\n");
    display(ptr1,row1,col1);
    printf("\n\n---------------2nd Array elements are:----------------------\n\n");
    display(ptr2,row2,col2);

    printf("\n\n-----------Result for Array multiplication is:--------------\n");
    arr_multiply(ptr1,ptr2,ptr3,row1,row2,col1,col2);
    //display(ptr3,row1,col2);

    int i,j;
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col2;j++)
        {
            printf("%4d ",*(*(ptr3+i)+j));
        }
        printf("\n");
    }

    deallocate(ptr1,row1,col1);
    deallocate(ptr2,row2,col2);
    deallocate(ptr3,row1,col2);

    return 0;
}

