#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;
void create_SLL(int);
void check_cycle();
int main()
{
    int n;
    printf("\nEnter size of linked list: ");
    scanf("%d",&n);
    create_SLL(n);
    check_cycle();
    printf("\n\n");
    return 0;
}
void create_SLL(int n)
{
    node *ptr=head;
    int choice,pos,i;
    while(n--)
    {
        node *new_node=(node *)malloc(sizeof(node));
        new_node->next=NULL;
        printf("\nEnter data: ");
        scanf("%d",&new_node->data);
        if(head==NULL)
            head=ptr=new_node;
        else
        {
            ptr->next=new_node;
            ptr=ptr->next;
        }
    }
    printf("\nEnter choice:\n1.Create cycle\n2.Do not create cycle\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\nThe nodes are: ");
        ptr=head;
        node *preptr=NULL;
        do
        {
            printf("%d ",ptr->data);
            preptr=ptr;
            ptr=ptr->next;
        }while(ptr!=NULL);
        printf("\nEnter position at which you want to connect the last node with: ");
        scanf("%d",&pos);
        node *ptr2=head;
        while(--pos)
            ptr2=ptr2->next;
        preptr->next=ptr2;
    }
    else if(choice==2)
        return;
    else
        printf("\nInvalid choice\nExiting without creating any cycle\n");
}

void check_cycle()
{
    node *fast,*slow;
    fast=slow=head;
    do
    {
        fast=fast->next;
        slow=slow->next;
        if(fast)
            fast=fast->next;
    }while(fast!=NULL && fast!=slow);

    if(fast==slow)
    {
        slow=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        printf("\nThe linked list has a cycle present and the intersection node is: %d",fast->data);
    }
    else
        printf("\nThe linked list has no cycle present\n");
}
