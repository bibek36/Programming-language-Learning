
/*  Problem->   WAP to solve fractional Knapsack problem using Greedy strategy. Observe the
               solution given by your program by considering the following greedy strategy:
                i)	fill up the Knapsack by taking objects which has the highest profit per unit weight
                 Check your program for the data set: N=3, M=20, <p1, p2, p3>=<25, 24, 15>,
                    <w1, w2, w3>=<18, 15, 10>
*/

#include<stdio.h>

int max_ppw(float [],int);
int main()
{
    int n=3,m=20;
    int i;

    int profit[]={25,24,15};
    int weight[]={18,15,10};
    float ppw[n];
    /*printf("\nEnter profit: ");
    scanf("%d%d%d",&profit[0],&profit[1],&profit[2]);

    printf("\nEnter weight: ");
    scanf("%d%d%d",weight[0],weight[1],weight[2]);
    */

    for(i=0;i<n;i++)
    {
        ppw[i]=(float)profit[i]/weight[i];
    }
    i=m;
    int j=0,wt=0;
    float pft=0;
    int max_element;
    int sequence[n];

    while(i!=0 && j<=n)
    {
        max_element=max_ppw(ppw,n);

        if(weight[max_element]<=i)
        {
            pft+=profit[max_element];
            wt+=weight[max_element];
            i-=weight[max_element];
            ppw[max_element]=0;
            sequence[j]=max_element+1;
            j++;
        }
        else
        {
            pft+=i*ppw[max_element];
            wt+=i;
            ppw[max_element]=0;
            i-=i;
            sequence[j]=max_element+1;
            j++;
        }

    }

    printf("\nUsing Greedy Method:\nProfit: %.2lf\nCorresponding Weight: %d\nSequence of choice: p%d,p%d,p%d\n",pft,wt,sequence[0],sequence[1],sequence[2]);

    return 0;
}

int max_ppw(float ppw[],int n)
{
    float max=ppw[0];
    int i=0,j=0;
    for(;i<n;i++)
    {
        if(ppw[i]>=max)
        {
            max=ppw[i];
            j=i;
        }
    }

    return j;
}

