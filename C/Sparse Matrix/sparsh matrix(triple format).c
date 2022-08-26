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
int main()
{
    sparse s;
    create(&s);
    display(&s);
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

