
                                    //Addition Not Working

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int i,j,x;
}element;

typedef struct
{
    int row;
    int col;
    int NNZ;                                                   //NNZ - Number of Non Zero Element
    element *e;
}sparse;
void create(sparse *s);
void display(sparse *s);
void add_sparse(sparse *s1,sparse *s2);
int main()
{
    sparse s1,s2;
    printf("Create 1st Sparse Matrix--\n");
    create(&s1);
    printf("\n--------------------------------------------------------------\n\n");
    printf("Create 2nd Sparse Matrix--\n");
    create(&s2);

    printf("\nThe first matrix is:\n");
    display(&s1);
    printf("\nThe second matrix is:\n");
    display(&s2);
    printf("\n--------------------------------------------------------------\n\n");
    printf("Adding two matrix: ");
    printf("\n\nThe Resultant matrix is:\n");
    add_sparse(&s1,&s2);

    return 0;
}

void create(sparse *s)
{
    printf("\nEnter dimension of matrix: ");
    scanf("%d %d",&s->row,&s->col);
    printf("\nEnter number of Non Zero Elements: ");
    scanf("%d",&s->NNZ);
    s->e=(int *)malloc(s->NNZ*sizeof(element));
    int i,j;
    for(i=0;i<s->NNZ;i++)
    {
        printf("\nEnter row Number: ");
        scanf("%d",&s->e[i].i);
        printf("\nEnter column Number: ");\
        scanf("%d",&s->e[i].j);
        printf("\nEnter the Non-Zero Element: ");
        scanf("%d",&s->e[i].x);
        printf("\n");
    }
    //display(s->e);
    //free(s->e);
}

void display(sparse *s)
{
    int i,j,k=0;
    for(i=0;i<s->row;i++)
    {
        for(j=0;j<s->col;j++)
        {
            if(i==s->e[k].i && j==s->e[k].j)
                printf("%d ",s->e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }

}

void add_sparse(sparse *s1,sparse*s2)
{
    if(s1->row!=s2->row && s2->col!=s2->col)
    {
        printf("\nMatrix cannot be Added\n\n");
        return 0;
    }
    sparse *sum;
    sum=(int *)malloc(sizeof(sparse));
    sum->row=s1->row;
    sum->col=s1->col;
    sum->e=(int *)malloc((s1->NNZ+s2->NNZ)*sizeof(element));
    int i=0,j=0,k=0;
    while(i<s1->row && j<s2->col)
    {
        if(s1->e[i].i < s2->e[i].i)
            sum->e[k++]=s1->e[i++];

        else if(s1->e[i].i > s2->e[i].i)
            sum->e[k++]=s2->e[j++];

        else
        {
            if(s1->e[i].j < s2->e[i].j)
                sum->e[k++]=s1->e[i++];

            else if(s1->e[i].j > s2->e[i].j)
                sum->e[k++]=s2->e[j++];

            else
            {
                sum->e[k++]=s1->e[i++];
                sum->e[k++].x+=s2->e[j++].x;
            }
        }
    }
    display(sum);


    /*for(i=0;i<sum->row;i++)
    {
        for(j=0;j<sum->col;j++)
        {
            if(i==sum->e[k].i && j==sum->e[k].j)
                printf("%d ",sum->e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
    */

}
