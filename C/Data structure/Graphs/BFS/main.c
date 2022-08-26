#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"
node *tree=NULL;
node *create_tree(node **,int);
void display_tree(node **,int);
void BFS(node **,int,int);
int main()
{
    printf("\n\n\t\t\t\t\t\tBREATH FOR SEARCH\n\n");
    int choice,pos,v;
    do
    {
        printf("Menu:\n1.Create Tree(By Adj. list method)\n2.Display tree\n3.Perform BFS\n4.Exit\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("\nEnter number of vertices: ");
                    scanf("%d",&v);
                    node *vertice=(node **)malloc(sizeof(int *));
                    //node *vertice[v];
                    tree=create_tree(vertice,v);
                    printf("\nTree created Successfully\n");
                    break;
            case 2:
                    display_tree(vertice,v);
                    break;
            case 3:
                    printf("\nEnter vertex from which you want to perform BFS: ");
                    scanf("%d",&pos);
                    BFS(vertice,v,pos);
                    break;
            case 4:
                    return 0;
                    break;
            default: printf("\nInvalid Input\n");
        }
    }while(1);
}

node *create_tree(node **vertice,int v)
{
    int i=0,num,n;
    while(i<v)
    {
        printf("\nEnter number of vertices adjacent to vertix %d : ",i+1);
        scanf("%d",&num);
        head=NULL;
        printf("\nEnter vertices adjacent to %d:\n",i+1);
        while(num--)
        {
            scanf("%d",&n);
            vertice[i]=Insert(n);
        }
        i++;
    }
    return vertice[0];
}

void display_tree(node **vertice,int v)
{
    int i=0;
    printf("\nVertex\t\tAdjacent Vertices");
    while(i<v)
    {
        printf("\n%d\t->\t",i+1);
        display(vertice,i);
        i++;
    }
    printf("\n\n");
}

void BFS(node **vertice,int v,int pos)
{
    int n,i=0,j,check=0;
    int *ver=(int *)calloc(v+1,sizeof(int));
    node *ptr=NULL;
    int cross_edge[2*v];
    printf("BFS Result: ");
    printf("%d->",pos);
    ver[pos]=1;
    enqueue(pos);
    while(!isEmpty())
    {
        n=dequeue();
        ptr=vertice[n-1];
        while(ptr!=NULL)
        {
            check=0;
            if(ver[ptr->data]==0)
            {
                printf("%d->",ptr->data);
                ver[ptr->data]=1;
                enqueue(ptr->data);
            }
            for(j=1;j<v+1;j++)
            {
                if(ver[j]!=1)
                {
                    check=1;
                    break;
                }
            }
            if(check==1)
            {
                cross_edge[i++]=n;
                cross_edge[i++]=ptr->data;
            }
            ptr=ptr->next;
        }
    }
    printf("\nCross Edges:");
    for(j=0;j<i/2;j++)
    {
        if(j%2==0)
            printf("\n");
        printf("%d->",cross_edge[j]);
    }
    printf("\n\n");
}
