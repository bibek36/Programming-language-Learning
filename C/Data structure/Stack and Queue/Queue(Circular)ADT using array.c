
                            //Queue(Circular)ADT using array
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
}queue;
queue q1;
void create_queue(queue *q);
void enqueue(queue *q1);
int dequeue(queue *q1);
void display(queue *q1);

int main()
{
    int choice,x;
    do
    {
        printf("\n\nEnter choice:\n1.Create Queue\n2.Insert in queue\n3.Delete from queue\n4.Display Queue\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create_queue(&q1);
                    break;
            case 2: enqueue(&q1);
                    break;
            case 3: x=dequeue(&q1);
                    if(x==-1)
                        printf("\nThe queue is Empty\n");
                    else
                        printf("\nThe deleted element is %d\n",x);
                    break;
            case 4: display(&q1);
                    break;
            case 5: return 0;
                    break;
            default: printf("\nInvalid Input\n");
        }
    }while(1);
}

void create_queue(queue *q)
{
    q->front=q->rear=0;
    printf("\nEnter size of Queue: ");
    scanf("%d",&q->size);
    q->size++;
    q->Q=(int *)malloc(q->size*sizeof(int));

}

void enqueue(queue *q)
{
    if((q->rear+1)%q->size == q->front)
    {
        printf("\nThe queue is full\n");
        return;
    }
    else
    {
        int x;
        printf("\nEnter data: ");
        scanf("%d",&x);
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        return x;
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void display(queue *q)
{
    if(q->front==q->rear)
    {
        printf("\nThe Queue is Empty\n");
        return;
    }
    else
    {
        int i=q->front+1;
        printf("\n\nQueue data are: ");
        do
        {
            printf("%d ",q->Q[i]);
            i=(i+1)%q->size;
        }while(i!=(q->rear+1)%q->size);
    }
}
