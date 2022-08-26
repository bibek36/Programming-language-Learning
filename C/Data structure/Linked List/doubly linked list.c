                                    //DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;
node *head=NULL;
void create();
void insert(int pos,int x);
void display();
int lenght();
int delete_pos(int);
void reverse();

int main()
{
    int choice,pos,x,len;
    printf("\n--------------------DOUBLY LINKED LIST-------------------\n");
    do
    {
        printf("\nEnter choice:\n1.Create\n2.Display\n3.Insert at any position\n4.Delete at any position\n5.Number of nodes in Linked List\n6.Reverse the Linked List\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    printf("\nDoubly Linked List Created Successfully\n");
                    break;
            case 2: display();
                    break;
            case 3: printf("\n\nEnter position you want to enter: ");
                    scanf("%d",&pos);
                    printf("\nEnter data: ");
                    scanf("%d",&x);
                    insert(pos,x);
                    break;
            case 4: printf("\n\nEnter position you want to delete: ");
                    scanf("%d",&pos);
                    x=delete_pos(pos);
                    if(x!=-1)
                        printf("\nThe deleted element is: %d",x);
                    break;
            case 5: len=length();
                    printf("\n\nTotal Number of nodes currently are: %d\n",len);
                    break;
            case 6: reverse();
                    break;
            case 7: return 0;
            default: printf("\n\nInvalid Input\n");
        }
    }while(1);
}

void create()
{
    int num;
    node *ptr=head,*new_node;
    printf("\nEnter number of nodes you want to create: ");
    scanf("%d",&num);
    while(num--)
    {
        new_node=(node *)malloc(sizeof(node));
        if(new_node==NULL)
        {
            printf("\nOverflow Condition\n");
            return;
        }
        printf("\nEnter data: ");
        scanf("%d",&new_node->data);
        if(head==NULL)
        {
            head=new_node;
            new_node->prev=NULL;
            new_node->next=NULL;
            ptr=new_node;
        }
        else
        {
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
            ptr=ptr->next;
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    node *ptr=head;
    printf("\nElement in the list are: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}

int length()
{
    node *ptr=head;
    if(head==NULL)
        return 0;
    int len=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        len++;
    }
    return len;
}
void insert(int pos,int x)
{
    node *ptr=head,*new_node;
    new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\nOverflow Condition\n");
        return;
    }
    new_node->data=x;
    new_node->next=NULL;
    if(pos>length()+1 || pos<1)
    {
        printf("\nInvalid input of position\n");
        return;
    }
    if(head==NULL && pos==1)
    {
        head=new_node;
        new_node->prev=NULL;
        new_node->next=NULL;
    }
    if(pos==1)
    {
        new_node->next=head;
        new_node->prev=NULL;
        head->prev=new_node;
        head=new_node;
    }
    else
    {
        int i;
        for(i=0;i<pos-2 ; i++)
            ptr=ptr->next;

        new_node->next=ptr->next;
        new_node->prev=ptr;
        ptr->next=new_node;
        if(ptr->next!=NULL)                                     //if inserting in last position
            ptr->next->prev=new_node;

    }
}

int delete_pos(int pos)
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return -1;
    }
    if(pos>length() || pos<1)
    {
        printf("\nInvalid input of position\n");
        return -1;
    }
    int i,x;
    if(length()==1 && pos==1)
    {
        x=ptr->data;
        free(ptr);
        head=NULL;
        return x;
    }
    if(pos==1)
    {
        head=head->next;
        head->prev=NULL;
        x=ptr->data;
        free(ptr);
        return x;
    }
    else
    {
        for(i=0;i<pos-1;i++)
            ptr=ptr->next;

        ptr->prev->next=ptr->next;
        if(ptr->next!=NULL)                                   //if last position is to be deleted
            ptr->next->prev=ptr->prev;
        x=ptr->data;
        free(ptr);
        return x;
    }
}

void reverse()
{
    node *ptr=head;
    node *temp;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    while(ptr!=NULL)
    {
        temp=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=temp;
        ptr=ptr->prev;
       if(ptr!=NULL && ptr->next==NULL)
            head=ptr;
    }

}
