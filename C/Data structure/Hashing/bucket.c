/*
Question:
        WAP in c to implement an open hashing scheme with say,100 buckets where the keys are integers in the range of 0-1000.
        show the following option:
        1.Insert
        2.Delete
        3.Display
        4.Search
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void insert(node**,int);
void delete(node**,int);
void display(node*);
void search(node**,int);
int main()
{
    int choice,i,key;
    node *ver=(node **)malloc(101*sizeof(node *));
    for(i=0;i<101;i++)
        ver[i]=NULL;
    do
    {
        printf("\nEnter choice:\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter key: ");
                    scanf("%d",&key);
                    insert(ver,key);
                    break;
            case 2: prinf("\nEnter key to be deleted: ");
                    scanf("%d",&key);
                    delete(ver,key);
                    break;
            case 3: display(ver);
                    break;
            case 4: printf("\nEnter key to be search: ");
                    scanf("%d",&key);
                    search(ver,key);
                    break;
            case 5: return 0;
            default: printf("\nInvalid input\n");
        }
    }while(1);
}
void insert(node **ver,int key)
{
    int i;
    if(key>100)
        i=key%100;
    else i=key;
    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\nHeap Full\n");
        return;
    }
    new_node->data=key;
    new_node->next=NULL;
    if(ver[i]==NULL)
    {
        ver[i]=new_node;
    }
    else
    {
        new_node->next=ver[i];
        ver[i]=new_node;
    }
}

void delete(node **ver,int key)
{
    int i,x=-1;
    if(key>100)
        i=key%100;
    else i=key;
    if(ver[i]==NULL)
    {
        printf("\nKey not found\n");
        return;
    }
    else
    {
        node *ptr=ver[i];
        node *preptr=NULL;
        while(ptr && ptr->data!=key)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr)
        {
            preptr->next=ptr->next;
            x=ptr->data;
            free(ptr);
        }
    }
    if(x!=-1)
    {
        printf("\nKey %d is deleted\n",x);
        return;
    }
    printf("\nKey not found\n");
}

void display(node *ver)
{
    int i,j;
    printf("The Hashing scheme is:\n");
    for(j=0;j<101;j++)
    {
        if(ver[j]==NULL)
            printf("%d\t-\tEmpty\n",j);
        else
        {
            node *ptr=ver[j];
            printf("%d\t-\t",j);
            while(ptr)
            {
                printf("%d->",ptr->data);
                ptr=ptr->next;
            }
        }
    }
}

void search(node **ver,int key)
{
    int i,x=0;
    if(key>100)
        i=key%100;
    else i=key;

    if(ver[i]==NULL)
    {
        printf("\nKey not found\n");
        return ;
    }

    node *ptr=ver[i];
    while(ptr)
    {
        if(ptr->data==key)
        {
            x++;
            printf("The key is found in %d bucket and %d position\n",i,x);
            return;
        }
    }
    printf("\nKey not found\n");
}
