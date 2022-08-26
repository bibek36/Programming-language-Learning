#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//#include "stack.h"
typedef struct node
{
    struct node *lchild,*rchild;
    int data;
}node;
node *root=NULL;
node *create_tree(int );
/*void preorder_ite(node *);
void preorder_rec(node *);
void inorder_ite(node *);
void inorder_rec(node *);
void postorder_ite(node *);
void postorder_rec(node *);
*/
int main()
{
    int choice,x;
    printf("Menu:\n1.Create Tree\n2.Perform Search\n3.Exit");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter data for root: ");
                scanf("%d",&x);
                root=create_tree(x);
                break;
        /*case 2: printf("\nEnter choice:\n1.Preorder Search\n2.Inorder Search\n3.Postorder Search\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1: printf("\nEnter choice:\n1.Iterative\n2.Recursive\n");
                            scanf("%d",&choice);
                            switch(choice)
                            {
                                case 1: preorder_ite(root);
                                        printf("\n\n");
                                        break;
                                case 2: preorder_rec(root);
                                        printf("\n\n");
                                        break;
                                default: printf("\nInvalid choice\n");
                            }
                            break;
                    case 2: printf("\nEnter choice:\n1.Iterative\n2.Recursive\n");
                            scanf("%d",&choice);
                            switch(choice)
                            {
                                case 1: inorder_ite(root);
                                        printf("\n\n");
                                        break;
                                case 2: inorder_rec(root);
                                        printf("\n\n");
                                        break;
                                default: printf("\nInvalid choice\n");
                            }
                            break;
                    case 3: printf("\nEnter choice:\n1.Iterative\n2.Recursive\n");
                            scanf("%d",&choice);
                            switch(choice)
                            {
                                case 1: postorder_ite(root);
                                        printf("\n\n");
                                        break;
                                case 2: postorder_rec(root);
                                        printf("\n\n");
                                        break;
                                default: printf("\nInvalid choice\n");
                            }
                            break;

                    default: printf("\nInvalid choice\n");
                }
        case 3: return 0;
        default: printf("\nInvalid choice\n");
*/    }

}

node *create_tree(int x)
{
    node *ptr=NULL;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(root);
    printf("%d",12);
    while(!isEmpty())
    {
        ptr=dequeue();
        printf("\nEnter left child of %d: ",ptr->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            node *temp=(node *)malloc(sizeof(node));
            temp->data=x;
            temp->rchild=temp->lchild=NULL;
            ptr->lchild=temp;
            enqueue(temp);
        }

        printf("\nEnter right child of %d: ",ptr->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            node *temp=(node *)malloc(sizeof(node));
            temp->data=x;
            temp->rchild=temp->lchild=NULL;
            ptr->rchild=temp;
            enqueue(temp);
        }
    }
    printf("\nTree created Successfully\n\n");
    return root;
}

/*void preorder_rec(node *ptr)
{
    printf("\nPreorder Search result: ");
    while(ptr)
    {
        printf("%d->",ptr->data);
        preorder_rec(ptr->lchild);
        preorder_rec(ptr->rchild);
    }
}

void inorder_rec(node *ptr)
{
    printf("\nInorder Search result: ");
    while(ptr)
    {
        printf("%d->",ptr->data);
        inorder_rec(ptr->lchild);
        inorder_rec(ptr->rchild);
    }
}

void postorder_rec(node *ptr)
{
    printf("\nPostorder Search result: ");
    while(ptr)
    {
        printf("%d->",ptr->data);
        postorder_rec(ptr->lchild);
        postorder_rec(ptr->rchild);
    }
}

void preorder_ite(node *ptr)
{
    stack st;
    printf("\nPreorder Search result: ");
    while(ptr!=NULL || !isEmpty(st))
    {
        if(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            push(&st,ptr);
            ptr=ptr->lchild;
        }
        else
        {
            ptr=pop(&st);
            ptr=ptr->rchld;
        }
    }
}

void inorder_ite(node *ptr)
{

}

void postorder_ite(node *ptr)
{

}
*/
