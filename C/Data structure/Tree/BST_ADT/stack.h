#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int info;
    struct stack *next;
}stack;
stack *top=NULL;
void push(int x)
{
    stack *new_node;
    new_node=(stack *)malloc(sizeof(stack));
    if(new_node==NULL)
    {
        printf("Stack Overflow condition");
        return;
    }
    new_node->info=x;
    new_node->next=NULL;
    if(top==NULL)
        top=new_node;
    else
    {
        new_node->next=top;
        top=new_node;
    }
}

int pop()
{
        int x=-1;
        stack *ptr=top;
        if(top==NULL)
            return x;
        else
        {
            top=top->next;
            x=ptr->info;
            free(ptr);
        }
        return x;
}

int isEmpty()
{
   if(top==NULL)
        return 1;
   else
        return 0;
}

