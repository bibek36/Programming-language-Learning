
                            //Singly Linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;
node *Insert(int);
void display(node **,int);

node *Insert(int info)
{
    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("Overflow Condition");
        return NULL;
    }
    new_node->data=info;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
    return head;
}

void display(node **vertice,int i)
{
    node *ptr=vertice[i];
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
}

