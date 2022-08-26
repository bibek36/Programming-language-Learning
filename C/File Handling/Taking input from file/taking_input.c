
#include<stdio.h>
int main()
{
    int n=3,i;
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

    //Printing the Content of file
    int profit[n];
    int weight[n];
    printf("The content of the files:\n");
    //Profit content
    printf("Profit: ");
    i=0;
    int num;
    while(fscanf(fp, "%d", &num) > 0) {
        profit[i] = num;
        i++;
    }
    for(i=0;i<n;printf("%d ",profit[i]),i++);

    //Weight content
    printf("\nWeight: ");
    i=0;
    while(fscanf(fpr, "%d", &num) > 0) {
        weight[i] = num;
        i++;
    }
    for(i=0;i<n;printf("%d ",weight[i]),i++);

    //Closing the file
    fclose(fp);
    fclose(fpr);
    return 0;
}
