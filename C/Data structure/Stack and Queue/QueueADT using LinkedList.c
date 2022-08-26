
                            //QueueADT using LinkedList
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *front=NULL;
node *rear=NULL;
void create();
void enqueue(int x);
int dequeue();
void display();
int main()
{
    int choice,x;
    do
    {
        printf("\n\nEnter choice:\n1.Create Queue\n2.Insert in queue\n3.Delete from queue\n4.Display Queue\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: printf("\nEnter new element: ");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 3: x=dequeue();
                    if(x==-1)
                        printf("\nThe queue is Empty\n");
                    else
                        printf("\nThe deleted element is %d\n",x);
                    break;
            case 4: display();
                    break;
            case 5: return 0;
                    break;
            default: printf("\nInvalid Input\n");
        }
    }while(1);
}

void create()
{
    node *new_node;
    front=rear=NULL;
    int n;
    printf("\nEnter number of nodes to be created: ");
    scanf("%d",&n);
    while(n--)
    {
        new_node=(node *)malloc(sizeof(node));
        if(new_node==NULL)
        {
            printf("\nOverflow condition\n");
            return;
        }
        printf("\nEnter data: ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(rear==NULL)
            front=rear=new_node;
        else
        {
            rear->next=new_node;
            rear=rear->next;
        }
    }
    printf("\nQueue Created Successfully\n\n");
}

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
    if(front==NULL)
        front=rear=new_node;
    else
    {
        rear->next=new_node;
        rear=rear->next;
    }
}

int dequeue()
{
    int x=-1;
    if(front==NULL)
        return x;
    node *temp=front;
    front=front->next;
    x=temp->data;
    free(temp);
    return x;
}

void display()
{
    if(front==NULL)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    node *temp=front;
    printf("\nQueue elements are: ");
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}
