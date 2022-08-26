#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef struct node
{
    struct node *lchild,*rchild;
    int data;
}node;
node *root=NULL;
node *temp=NULL;
node *insert(node *,int);
node *Delete(node *,int);
node *Rsearch(node *,int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
int height(node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);

    return x>y?x+1:y+1;
}
node *inpre(node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
node *insuc(node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}
int main()
{
    int choice,key;
    node *ptr;
    printf("\n\t\t\t\t****************Binary Search Tree*****************\n");
    do
    {
        printf("\nEnter choice:\n1.Insert in BST\n2.Delete from BST\n3.Search element from BST\n4.Perform Search\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter data: ");
                    scanf("%d",&key);
                    root=insert(root,key);
                    printf("\nInserted Successfully\n");
                    break;
            case 2: printf("\nEnter element to be deleted: ");
                    scanf("%d",&key);
                    ptr=Delete(root,key);
                    if(ptr==NULL)
                        printf("\nElement not found\n");
                    //else
                    //    printf("\nDeleted element is %d\n",temp->data);
                    break;
            case 3: printf("\nEnter element to be searched: ");
                    scanf("%d",&key);
                    ptr=Rsearch(root,key);
                    if(ptr==NULL)
                        printf("\nElement is not present in BST\n");
                    else
                        printf("\nThe Address of the searched element %d is : %p",ptr->data,ptr);
                    break;
            case 4: printf("\nEnter choice:\n1.Preorder\n2.Inorder\n3.Postorder\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: printf("\nPreorder Result: ");
                                preorder(root);
                                printf("\n\n");
                                break;
                        case 2: printf("\nInorder Result: ");
                                inorder(root);
                                printf("\n\n");
                                break;
                        case 3: printf("\nPostorder Result: ");
                                postorder(root);
                                printf("\n\n");
                                break;
                        default :printf("\nInvalid Input\n");
                    }
                    break;
            case 5: return 0;
            default :printf("\nInvalid Input\n");
        }
    }while(1);
}

node *insert(node *p,int key)
{
    node *t=NULL;
    if(p==NULL)
    {
        t=(node *)malloc(sizeof(node));
        t->data=key;
        t->lchild=NULL;
        t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=insert(p->lchild,key);
    else if(key>p->data)
        p->rchild=insert(p->rchild,key);
    return p;
}


node *Delete(node *p,int key)
{
    node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        temp=p;
        return NULL;
    }
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=insuc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

node *Rsearch(node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    else if(key<p->data)
        return Rsearch(p->lchild,key);
    else
        return Rsearch(p->rchild,key);
}

void preorder(node *p)
{
    if(p==NULL)
    {
       printf("\nTree is Empty");
       return;
    }
    while(p!=NULL || !isEmpty())
    {
       if(p!=NULL)
       {
           printf("%d->",p->data);
           push(p);
           p=p->lchild;
       }
       else
       {
           p=pop();
           p=p->rchild;
       }
   }

  /* while(p)
   {
       printf("%d->",p->data);
       preorder(p->lchild);
       preorder(p->rchild);
   }
*/
}
void inorder(node *p)
{
   if(p==NULL)
   {
       printf("\nTree is Empty");
       return;
   }
   while(p!=NULL || !isEmpty())
   {
       if(p!=NULL)
       {
           push(p);
           p=p->lchild;
       }
       else
       {
           p=pop();
           printf("%d->",p->data);
           p=p->rchild;
       }
   }
   /*while(p)
   {
       inorder(p->lchild);
       printf("%d->",p->data);
       inorder(p->rchild);
   }
    */
}
void postorder(node *p)
{
   if(p==NULL)
   {
       printf("\nTree is Empty");
       return;
   }
   long int t;
   while(p!=NULL || !isEmpty())
   {
       if(p!=NULL)
       {
           push(p);
           p=p->lchild;
       }
       else
       {
           t=pop();
           if(t>0)
           {
               push(-t);
               p=((node *)t)->rchild;
           }
           else
           {
               printf("%d->",((node *)t)->data);
               p=NULL;
           }
       }
   }

   /*while(p)
   {
       postorder(p->lchild);
       postorder(p->rchild);
       printf("%d->",p->data);
   }
   */
}
