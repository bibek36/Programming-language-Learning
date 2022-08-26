                                    //SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void Delete_begin();
void Delete_end();
void Delete_pos();
void count();
void reverse();
struct node
{
        int info;
        struct node *next;
};
struct node *head=NULL;
int main()
{
        int choice;
        while(1)
        {
                printf("\n1.creating linked list\n");
                printf("\n2.display \n");
                printf("\n3.Inset at the begining\n");
                printf("\n4.Insert at the end \n");
                printf("\n5.Insert at specified positon\n");
                printf("\n6.Delete from begining\n");
                printf("\n7.Delete from end\n");
                printf("\n8.Delete from specified position\n");
                printf("\n9.count the number of nodes\n");
                printf("\n10.reverse of linked list\n");
                printf("\n11.exit \n");
                printf("\nEnter the choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("\nCreating linked list\n");
                                create();
                                break;
                        case 2: printf("\nDisplaying linked list\n");
                                display();
                                break;
                        case 11: exit(0);
                                break;
                        case 3: printf("\nInsert at begin\n");
                                insert_begin();
                                break;
                        case 4: printf("\nInsert at end\n");
                                insert_end();
                                break;
                        case 5: printf("\nInsert at position\n");
                                insert_pos();
                                break;
                        case 6: printf("\nDelete from begin\n");
                                Delete_begin();
                                break;
                        case 7: printf("\nDelete from end\n");
                                Delete_end();
                                break;
                        case 8: printf("\nDelete from position\n");
                                Delete_pos();
                                break;
                        case 9: printf("\nCount the nodes\n");
                                count();
                                break;
                        case 10: printf("\nReverse the list\n");
                                 reverse();
                                 break;
                        default: printf("\nwrong choice\n");
                                 break;
                }
        }
        return 0;
}
void create()
{
        struct node *New_node,*ptr;
        int num;
        printf("Enter the number upto which linked list creates\n");
        scanf("%d",&num);
        head=ptr=NULL;
        while(num)
        {
                New_node=(struct node*)malloc(sizeof(struct node));
                printf("\n Enter the data value for the node:\n");
                scanf("%d",&New_node->info);
                New_node->next=NULL;
                if(head==NULL)
                        head=ptr=New_node;
                else
                {
                        ptr->next=New_node;
                        ptr=ptr->next;
                }
                num--;
        }
}
void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("\nThe list is empty:\n");
                return;
        }
        else
        {
                ptr=head;
                printf("\nThe list elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->info);
                        ptr=ptr->next;
                }
        }
        printf("\n\n");
}
void insert_begin()
{
        struct node *New_node;
        if(head==NULL)
        {
            printf("\nUnderflow condition\n");
            return;
        }
        New_node=(struct node*)malloc(sizeof(struct node));
        if(New_node==NULL)
        {
                printf("\nOverflow condition\n");
                return;
        }
        else
        {
                printf("\nenter the data value for the node:\n");
                scanf("%d",&New_node->info);
                New_node->next=head;
                head=New_node;
        }
}
void insert_end()
{
        struct node *New_node, *ptr;
        if(head==NULL)
        {
            printf("\nUnderflow condition\n");
            return;
        }
	    New_node=(struct node*)malloc(sizeof(struct node));
        if(New_node==NULL)
        {
                printf("\nOverflow condition\n");
                return;
        }
        printf("\nenter the data value for the node:\n");
        scanf("%d",&New_node->info);
        New_node->next=NULL;
        ptr=head;
        while(ptr->next!=NULL)
        {
                ptr=ptr->next;
        }
        ptr->next=New_node;
}
void insert_pos()
{
        struct node *New_node, *ptr ,*preptr;
        if(head==NULL)
        {
            printf("\nUnderflow condition\n");
            return;
        }
        int count=0;
        New_node=(struct node*)malloc(sizeof(struct node));
        int i=0,pos;
        if(New_node==NULL)
        {
                printf("\noverflow condition\n");
                return;
        }
        ptr=head;
        while(ptr!=NULL)
        {
                count++;
                ptr=ptr->next;
        }
        printf("\nEnter the position you want to insert:\n");
        scanf("%d",&pos);
        if(pos>count)
        {
            printf("\nPosition not found\n");
            return;
        }
        else
        {
            printf("\nenter the data value for the node:\n");
            scanf("%d",&New_node->info);
            if(pos==0)
            {
                    New_node->next=head;
                    head=New_node;
            }
            else
            {
                    ptr=head;
                    while(pos!=0)
                    {
                            preptr=ptr;
                            ptr=ptr->next;
                            pos--;
                    }
                    preptr->next=New_node;
                    New_node->next=ptr;
            }
        }
}
void Delete_begin()
{
        struct node *ptr;
        int count=0;
        if(head==NULL)
        {
                printf("\nThe list is empty\n");
                return;
        }
         ptr=head;
        while(ptr!=NULL)
        {
                count++;
                ptr=ptr->next;
        }
        if(count==1)
        {
            ptr=head;
            printf("\n*************Deleted node=%d  ****************\n",head->info);
            free(head);
            head=NULL;
        }
        else
        {
                ptr=head;
                head=ptr->next;
                printf("\ndeleted node is %d \n",ptr->info);
                free(ptr);
        }
}
void Delete_end()
{
        struct node *ptr, *preptr;
        int count=0;
        if(head==NULL)
        {
                printf("\nThis list is empty\n");
                return;
        }
        ptr=head;
        while(ptr!=NULL)
        {
                count++;
                ptr=ptr->next;
        }
        if(count==1)
        {
            ptr=head;
            printf("\n*************Deleted node=%d  ****************\n",head->info);
            free(head);
            head=NULL;
        }
        else
        {
                ptr=preptr=head;
                while(ptr->next!=NULL)
                {
                        preptr=ptr;
                        ptr=ptr->next;
                }
                preptr->next=NULL;
                printf("\ndeleted node is %d \n",ptr->info);
                free(ptr);
        }
}
void Delete_pos()
{
        struct node *ptr, *preptr;
        int count=0,i,pos;
        if(head==NULL)
        {
                printf("\nThe list is empty\n");
                return;
        }
         ptr=head;
        while(ptr!=NULL)
        {
                count++;
                ptr=ptr->next;
        }
        printf("\nenter the position of the node to be deleted\n");
        scanf("%d",&pos);
        if(pos>count)
        {
            printf("\nPosition not found\n");
            return;
        }
        else
        {

                if(pos==0)
                {
                        ptr=head;
                        head=ptr->next;
                        printf("\n the deleted element is %d \n",ptr->info);
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++)
                        {
                                preptr=ptr;
                                ptr=ptr->next;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not found\n");
                                        return;
                                }
                        }
                        preptr->next=ptr->next;
                        printf("\nthe deleted node is %d \n",ptr->info);
                        free(ptr);
                }
        }
}
void count()
{
        struct node *ptr;
        if(head==NULL)
        {
            printf("\n***********There is no node***********\n");
            return;
        }
        int count=0;
        ptr=head;
        while(ptr!=NULL)
        {
                count++;
                ptr=ptr->next;
        }
        printf("total number of nodes=%d\n",count);
}
void reverse()
{
        struct node *ptr, *preptr;
        if(head!=NULL)
        {
                preptr=head;
                head=head->next;
                ptr=head;
                preptr->next=NULL;
                while(head!=NULL)
                {
                        head=head->next;
                        ptr->next=preptr;
                        preptr=ptr;
                        ptr=head;
                }
                head=preptr;
        }
}
