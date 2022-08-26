#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    int data;
    struct stack *next;
}stack;
stack *top=NULL;
int pref(char x)
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    return 0;
}
int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}
void push(char x)
{
    stack *new_node=(stack *)malloc(sizeof(stack));
    new_node->data=x;
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
        x=ptr->data;
        free(ptr);
        return x;
    }
}
char *In_to_Post(char *infix)
{
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pref(infix[i])>pref(stacktop()))
                push(infix[i++]);
            else
                postfix[j++]=pop();
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}
int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
int stacktop()
{
    if(top==NULL)
        return -1;
    else
        return top->data;
}
int evalute(char *postfix)
{
    int i=0,x1,x2;
    int r=0;
    for(;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2=pop();
            x1=pop();
            switch(postfix[i])
            {
                case '+':   r=x1+x2;
                            break;
                case '-':   r=x1-x2;
                            break;
                case '*':   r=x1*x2;
                            break;
                case '/':   r=x1/x2;
            }
            push(r);
        }
    }
    return top->data;
}
int main()
{
    char infix[20];
    int i;
    printf("\nEnter string: ");
    scanf("%[^\n]",infix);
    printf("\nThe Postfix expression is: ");
    char *postfix=In_to_Post(infix);
        printf("%s",postfix);
    printf("\n\nThe evaluated value is: %d\n",evalute(postfix));
    return 0;
}
