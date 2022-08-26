#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int **matrixOne,**matrixTwo,**resultMatrix,r1,c1,r2,c2;
    time_t start,end;
    srand(time(NULL));
    start=clock();
    do {
        printf("\n\n----Enter for Matrix One----\n");
        printf("Enter number of rows: ");
        scanf("%d",&r1);
        printf("Enter number of columns: ");
        scanf("%d",&c1);
        printf("\n---Enter for Matrix Two:---\n");
        printf("Enter number of rows: ");
        scanf("%d",&r2);
        printf("Enter number of columns: ");
        scanf("%d",&c2);
        if(c1!=r2)
            printf("\nMatrix Multiplication is NOT POSSIBLE(INVALID INPUT)");
        else
            break;
        }while(1);

    int i,j,k;
    matrixOne=(int**)malloc(r1*sizeof(int*));
    for(i=0;i<r1;i++)
        matrixOne[i]=(int*)malloc(c1*sizeof(int));
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            matrixOne[i][j]=rand()%10;
        }
    }

    matrixTwo=(int**)malloc(r2*sizeof(int*));
    for(i=0;i<r2;i++)
        matrixTwo[i]=(int*)malloc(c2*sizeof(int));
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            matrixTwo[i][j]=rand()%10;
        }
    }

    resultMatrix=(int**)malloc(r1*sizeof(int*));
    for(i=0;i<r1;i++)
        resultMatrix[i]=(int*)malloc(c2*sizeof(int));
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            resultMatrix[i][j]=0;
            for(k=0;k<c1;k++)
                resultMatrix[i][j]=matrixOne[i][k]*matrixTwo[k][j];
        }
    }

    printf("\nResultant Matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
            printf("%d ",resultMatrix[i][j]);
        printf("\n");
    }

    end=clock();
    printf("\nTime taken for Program execution is=%.2f Sec",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
