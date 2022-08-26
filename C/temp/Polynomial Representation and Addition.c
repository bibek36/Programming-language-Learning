
                        //Polynomial Representation-Working
                        //Addition-Not Working

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int coeff,expo;
}term;

typedef struct
{
    int n;                          //no.of non zero terms in polynomial
    term *t;
}poly;

void create(poly *p);
void display(poly p);
void add_poly(poly p1,poly p2);
int main()
{
    poly p1,p2;
    printf("\n-----------------------Enter for 1st Polynomial----------------------------");
    create(&p1);
    printf("\n\n-----------------------Enter for 1st Polynomial----------------------------");
    create(&p2);
    printf("\nDisplaying polynomial 1:");
    display(p1);
    printf("\nDisplaying polynomial 2:");
    display(p2);

    printf("\n\n-------------------Displaying The Resultant Polynomial after addition------------\n");
    add_poly(p1,p2);
    return 0;
}

void create(poly *p)
{
    printf("\nEnter number of elements: ");
    scanf("%d",&p->n);

    p->t=(int *)malloc(p->n*sizeof(term));

    int i;
    printf("\n\t\t\t------\tEnter Polynomial\t-----");
    for(i=0;i<p->n;i++)
    {
        printf("\nEnter for term number %d:\n",i+1);
        printf("Coefficient: ");
        scanf("%d",&p->t[i].coeff);
        printf("Exponential: ");
        scanf("%d",&p->t[i].expo);
    }

}

void display(poly p)
{
    int i;
    printf("\nP(X)=");
    for(i=0;i<p.n;i++)
    {
        if(i==p.n-1)
            {
                printf("%dX^%d ",p.t[i].coeff,p.t[i].expo);
                continue;
            }
        printf("%dX^%d + ",p.t[i].coeff,p.t[i].expo);
    }

}

void add_poly(poly p1,poly p2)
{
    poly p3;
    p3.t=(int *)malloc((p1.n+p2.n)*sizeof(term));
    int i=0,j=0,k=0;
    while(i<p1.n && j<p2.n)
    {
        if(p1.t[i].expo > p2.t[j].expo)
            p3.t[k++]=p1.t[i++];

        else if(p1.t[i].expo < p2.t[j].expo)
            p3.t[k++]=p2.t[j++];

        else
        {
                p3.t[k]=p1.t[i];
                p3.t[k++].coeff=p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    printf("\t%d\n\n",k);

    p3.t=(int *)realloc(p3.t,k*sizeof(term));
    display(p3);
}
