#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
node *tree=NULL;
node *create_tree(node **,int);
void display_tree(node **,int);
void DFS(node **,int,int,node *);
int main()
{
    printf("\n\n\t\t\t\t\t\t DEAPTH FOR SEARCH\n\n");
    int choice,pos,v;
    do
    {
        printf("Menu:\n1.Create Tree(By Adj. list method)\n2.Display tree\n3.Perform DFS\n4.Exit\nEnter Choice: ");
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
                    printf("\nEnter vertex from which you want to perform DFS: ");
                    scanf("%d",&pos);
                    printf("DFS Result: ");
                    printf("%d->",pos);
                    int *ver=(int *)calloc(v+1,sizeof(int));
                    DFS(vertice,v,pos,ver);
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

void DFS(node **vertice,int v,int pos,node *ver)
{
    static int n,i=0;
    static node *ptr=NULL;
    //int back_edge[2*v];
    ptr=vertice[pos-1];
    if(ver[pos]==0)
    {
        printf("%d",pos);
        ver[i]=1;

        while(ptr)
        {
            ptr=ptr->next;
            DFS(vertice,v,ptr->data);
        }
        /*for(n=1;n<=v;n++)
        {
            if(ver[i]!=0)
            {
                DFS()
            }
        }*/
    }

}
