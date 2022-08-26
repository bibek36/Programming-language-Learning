
                        //Queue using linked list
#include<stdio.h>
#include<stdlib.h>
node *queue_head=NULL;
node *rear=NULL;
void enqueue(int x);
int dequeue();
int isEmpty();
node *create_queue_queue();

void enqueue(int x)
{
    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\nOverflow condition\n");
        return;
    }
    new_node->data=x;
    new_node->next=NULL;
    if(queue_head==NULL)
        queue_head=rear=new_node;
    else
    {
        rear->next=new_node;
        rear=rear->next;
    }
}

int dequeue()
{
    int x=-1;
    if(queue_head==NULL)
        return x;
    node *temp=queue_head;
    queue_head=queue_head->next;
    x=temp->data;
    free(temp);
    return x;
}

int isEmpty()
{
    if(queue_head==NULL)
        return 1;
    else
        return 0;
}
