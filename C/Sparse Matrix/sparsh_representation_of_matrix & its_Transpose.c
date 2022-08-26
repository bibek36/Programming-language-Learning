#include <stdio.h>

void read_matrix(int a[10][10], int row, int column);
void print_sparse(int b[20][3]);
int create_sparse(int a[10][10], int row, int column, int b[20][3]);
void transpose(int b[20][3],int row,int column,int k);

int main()
{
    int a[10][10], b[20][3], row, column,k;
    printf("\nEnter the size of matrix (rows, columns): ");
    scanf("%d%d", &row, &column);

    read_matrix(a, row, column);
    k=create_sparse(a, row, column, b);
    if(3*k+3>=row*column)
        {
            printf("\nUsing sparse representation is not Advantageous\n\n");
            return 0;
        }
    print_sparse(b);
    transpose(b,row,column,k+1);
    return 0;
}

void read_matrix(int a[10][10], int row, int column)
{
    int i, j;
    printf("\nEnter elements of matrix\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

int create_sparse(int a[10][10], int row, int column, int b[20][3])
{
    int i, j, k;
    k = 1;
    b[0][0] = row;
    b[0][1] = column;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k - 1;
    }
    return k-1;
}

void print_sparse(int b[20][3])
{
    int i, column;
    column = b[0][2];
    printf("\nSparse form - list of 3 triples\n\n");
    for (i = 0; i <= column; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

void transpose(int b[20][3],int row,int column,int k)
{
    int i,t,j,count=1;
    for(i=1;i<k;i++)
    {
        t=b[i][0];
        b[i][0]=b[i][1];
        b[i][1]=t;
    }
    int min=b[1][0];
    while(count!=k-1)
    {
        for(i=count++;i<k;i++)
        {
            if(b[i][0]<=min)
               {
                    min=b[i][0];
                    while(j<3)
                    {
                        t=b[i][j];
                        b[i][j]=b[i][j];
                        b[i][j]=t;
                        j++;
                    }
               }
        }

    }


    /*int c[20][3];
    c[0][0]= row;
    c[0][1]= column;
    c[0][3]=k;
    int min=b[1][1];
    int l=1,r2=1,c2=0,i;
    while(r2!=k-1)
    {
            for(i=1;i<row;i++)
        {
            if(b[i][1]<min)
                    {
                        min=b[i][1];
                        l=i;
                        if(i==row-1)
                        {
                            c[r2++][c2++]=b[l][0];
                            c[r2][c2++]=b[l][1];
                            c[r2][c2]=b[l][2];
                        }
                    }
        }
    }
    */
    printf("\n\nTranspose in sparse form of the given matrix is:\n");
    print_sparse(b);
}
