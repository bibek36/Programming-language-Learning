#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;
void create();
void display(node *ptr);

int main()
{
    int choice;
    do
    {
        printf("\n\nEnter choice:\n1.Create\n2.Display\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    printf("\nCircular Linked List is created\n\n");
                    break;

            case 2: display(head);
                    printf("\nElements in the Circular Linked List are: ");
                    break;

            case 3: return 0;
        }
    }while(1);

}

void create()
{
    node *new_node,*ptr;
    ptr=head;
    int num;
    printf("\nEnter number of data's: ");
    scanf("%d",&num);
    while(num)
    {
        new_node=(node *)malloc(sizeof(node));
        if(new_node==NULL)
        {
            printf("\nOverflow condition\n");
            return ;
        }
        printf("\nEnter Data: ");
        scanf("%d",&new_node->data);
        if(head==NULL)
        {
            head=new_node;
            new_node->next=new_node;
            ptr=head;
        }
        else
        {
            ptr->next=new_node;
            new_node->next=head;
            ptr=ptr->next;
        }

        num--;
    }

}

void display(node *ptr)
{
    static int flag=0;
    if(ptr!=head || flag==0)
    {
        flag=1;
        printf("%d ",ptr->data);
        display(ptr->next);
    }
}
