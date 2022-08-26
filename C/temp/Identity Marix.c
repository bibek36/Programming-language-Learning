                                //IDENTITY AND DIAGONAL MATRIX
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,i,j,flag=1;
    printf("\nEnter the number of row and column:");
    scanf("%d %d",&m,&n);
    int A[m][n];
    printf("\nEnter the elements of matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            {
                scanf("%d",&A[i][j]);
            }
    }
    printf("\nPrint matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                if(A[i][j]==1)
                    continue;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(A[i][j]<0 || A[i][j]!=0)
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("\nMatrix is identity Matrix ");
        printf("And also Diagonal Matrix\n");
    }
    if(flag==0)
    {
        printf("\nMatrix is not identity matrix");
        flag=1;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j&&A[i][j]!=0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            printf("\nBut it is Diagonal matrix\n");
        else
            printf("\nAnd also not Diagonal matrix\n\n");
    }
     return 0;
}
