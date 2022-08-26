# include<stdio.h>
# include<stdlib.h>
typedef struct Queue
{
    struct node *info;
    struct Queue *next;
}Queue;
Queue *front=NULL;
Queue *rear=NULL;

void enqueue(struct node **x)
{
    Queue *new_node=(struct node **)malloc(sizeof(struct node *));
    if(new_node==NULL)
    {
        printf("\nOverflow condition\n");
        return;
    }
    new_node->info=x;
    new_node->next=NULL;
    if(front==NULL)
        front=rear=new_node;
    else
    {
        rear->next=new_node;
        rear=rear->next;
    }
}

struct node *dequeue()
{
    struct node *x=NULL;
    if(front==NULL)
        return x;
    Queue *temp=front;
    front=front->next;
    x=temp->info;
    free(temp);
    return x;
}

int isEmpty()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}


/*
typedef struct queue
{
    struct node **data;
    struct queue *next;
    struct queue *front;
    struct queue *rear;
}queue;
front=NULL;
rear=NULL;
void enqueue(queue *q,struct node **ptr)
{
    queue *new_node;
    new_node=(struct node **)malloc(sizeof(struct node *));
    if(new_node==NULL)
    {
        printf("\nOverflow condition\n");
        return;
    }
    new_node->data=ptr;
    new_node->next=NULL;
    if(q->front==NULL)
        q->front=q->rear=new_node;
    else
    {
        q->rear->next=new_node;
        q->rear=q->rear->next;
    }
}

struct node *dequeue(queue *q)
{
    struct node *ptr=NULL;
    if(q->front==NULL)
        return ptr;
    queue *temp=q->front;
    q->front=q->front->next;
    ptr=temp->data;
    free(temp);
    return ptr;
}

int isEmpty(queue q)
{
    if(q.front==NULL)
        return 1;
    else
        return 0;
}
*/
