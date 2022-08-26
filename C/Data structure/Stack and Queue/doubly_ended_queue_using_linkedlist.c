
                                //DOUBLE ENDED QUEUE
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *front=NULL,*rear=NULL;
void enqueue_front();
void enqueue_rear();
int dequeue_front();
int dequeue_rear();
void display();
int main()
{
    int n,x,choice;
    printf("\n\t\t\t\t\tDoubly-ended Queue using Linked list\n\n");
    printf("Enter choice of Queue:\n1.Input Restricted\n2.Output Restricted\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: do
                {
                    printf("Enter choice: ");
                    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
                    scanf("%d",&n);
                    switch(n)
                    {
                        case 1: printf("\nEnter choice:\n1.Enqueue from front\n2.Enqueue from rear\n");
                                scanf("%d",&choice);
                                switch(choice)
                                {
                                    case 1: printf("\nEnqueue from front is not possible in Input Restricted Queue\n");
                                            break;
                                    case 2: enqueue_rear();
                                            break;
                                    default: printf("\nInvalid Input\n\n");
                                }
                                break;
                        case 2: printf("\nEnter choice:\n1.Dequeue from front\n2.Dequeue from rear\n");
                                scanf("%d",&choice);
                                switch(choice)
                                {
                                    case 1: x=dequeue_front();
                                            break;
                                    case 2: x=dequeue_rear();
                                            break;
                                    default: printf("\nInvalid Input\n\n");
                                }
                                if(x==-1)
                                    printf("\nQueue is Empty\n\n");
                                else
                                    printf("\nThe deleted element is: %d\n\n",x);
                                break;
                        case 3: display();
                                break;
                        case 4: return 0;
                        default: printf("\nInvalid input\n\n");
                    }
                }while(1);
                break;

        case 2: do
                {
                    printf("Enter choice: ");
                    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
                    scanf("%d",&n);
                    switch(n)
                    {
                        case 1: printf("\nEnter choice:\n1.Enqueue from front\n2.Enqueue from rear\n");
                                scanf("%d",&choice);
                                switch(choice)
                                {
                                    case 1: enqueue_front();
                                            break;
                                    case 2: enqueue_rear();
                                            break;
                                    default: printf("\nInvalid Input\n\n");
                                }
                                break;
                        case 2: printf("\nEnter choice:\n1.Dequeue from front\n2.Dequeue from rear\n");
                                scanf("%d",&choice);
                                switch(choice)
                                {
                                    case 1: x=dequeue_front();
                                            break;
                                    case 2: printf("\nDequeue from rear is not possible in Output Restricted Queue\n");
                                            break;
                                    default: printf("\nInvalid Input\n\n");
                                }
                                if(choice==2)
                                    break;
                                if(x==-1)
                                    printf("\nQueue is Empty\n\n");
                                else
                                    printf("\nThe deleted element is: %d\n\n",x);
                                break;
                        case 3: display();
                                break;
                        case 4: return 0;
                        default: printf("\nInvalid input\n\n");
                    }
                }while(1);
                break;

        default: printf("\nInvalid input\n\n");
    }
    return 0;
}

void enqueue_front()
{
    if(front==NULL)
    {
        printf("\nEnqueue from front for first element not possible\n\n");
        return;
    }

    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\nOverflow condition\n\n");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&new_node->data);
    new_node->next=front;
    front=new_node;
    printf("\nElement entered successfully\n\n");
}

void enqueue_rear()
{
    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\nOverflow condition\n");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(front==NULL)
        front=rear=new_node;
    else
    {
        rear->next=new_node;
        rear=rear->next;
    }
    printf("\nElement entered successfully\n\n");
}

int dequeue_front()
{
    int x=-1;
    if(front==NULL)
        return x;
    node *ptr=front;
    x=ptr->data;
    front=front->next;
    free(ptr);
    return x;
}

int dequeue_rear()
{
    int x=-1;
    if(front==NULL)
        return x;
    node *ptr=front;
    while(ptr->next!=NULL && ptr->next!=rear)
        ptr=ptr->next;
    x=rear->data;
    if(ptr==rear)
    {
        free(rear);
        front=rear=NULL;
        return x;
    }
    ptr->next=NULL;
    free(rear);
    rear=ptr;
    return x;
}

void display()
{
    if(front==NULL)
    {
        printf("\nThe queue is Empty\n\n");
        return;
    }
    printf("\nThe queue elements are: ");
    node *ptr=front;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=NULL);
    printf("\n\n");
}
