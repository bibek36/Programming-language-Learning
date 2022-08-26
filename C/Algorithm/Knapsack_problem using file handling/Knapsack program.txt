
/*  Problem->   WAP to solve fractional Knapsack problem using Greedy strategy. Observe the
               solution given by your program by considering the following greedy strategy:
                i)	fill up the Knapsack by taking objects which has the highest profit per unit weight
                 Check your program for the data set: N=3, M=20, <p1, p2, p3>=<25, 24, 15>,
                    <w1, w2, w3>=<18, 15, 10>
*/

#include<stdio.h>
int main()
{
    int n=3,i,m=20;

//Opening the text file in read mode
    FILE *fp,*fpr;
    fp = fopen("profit.txt","r");
    if(fp==NULL)
    {
        printf("\nUnable to open the profit file\n");
        return 1;
    }

    fpr = fopen("weight.txt","r");
    if(fpr==NULL)
    {
        printf("\nUnable to open the weight file\n");
        return 1;
    }

//Retrieving the Contents of file and storing it in an Array
    int profit[n];
    int weight[n];
    int num;
    printf("The content of the files:\n");
    //Profit content
    printf("Profit: ");
    i=0;
    while(fscanf(fp, "%d", &num) > 0)
    {
        profit[i] = num;
        i++;
    }
    for(i=0;i<n;printf("%d ",profit[i]),i++);
    //

    //Weight content
    printf("\nWeight: ");
    i=0;
    while(fscanf(fpr, "%d", &num) > 0)
    {
        weight[i] = num;
        i++;
    }
    for(i=0;i<n;printf("%d ",weight[i]),i++);
    //

//Solving Knapsack_problem using greedy method
    float ppw[n];
    for(i=0;i<n;i++)
    {
        ppw[i]=(float)profit[i]/weight[i];
    }

    //Creating a file to store profit per weight value
    FILE *file;
    file = fopen("report_ppw","w");
    int data[100];
    fputs("Profit: ",file);
    for(i=0;i<n;fprintf(file,"%d ",profit[i]),i++);
    fputs("\nWeight: ",file);
    for(i=0;i<n;fprintf(file,"%d ",weight[i]),i++);
    fputs("\nProfit per weight: ",file);
    for(i=0;i<n;fprintf(file,"%.2lf ",ppw[i]),i++);
    //

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

    printf("\n\nUsing Greedy Method:\nProfit: %.2lf\nCorresponding Weight: %d\nSequence of choice: p%d,p%d,p%d\n",pft,wt,sequence[0],sequence[1],sequence[2]);
//

//Closing the file
    fclose(fp);
    fclose(fpr);
    fclose(file);
//

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



