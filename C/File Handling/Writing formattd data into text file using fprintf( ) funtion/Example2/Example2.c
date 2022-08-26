#include<stdio.h>
#define SIZE 80
int main()
{
    FILE *fp,*fpr;
    fp = fopen("file.txt","r");     //EXCLUSIVE Reading Operation
    if(fp==NULL)
    {
        printf("Unable to open file");
        return 1;
    }

    fpr = fopen("report.txt","w");     //EXCLUSIVE Writing Operation
    if(fpr==NULL)
    {
        printf("Unable to open file");
        return 1;
    }
    //Reading and Writing Formatted data from text file using fscanf() function

    char names[SIZE];
    int salary;
    double perHRA;
    double houseRent;
    double netSalary;
    fprintf(fpr,"Names\t\t\t\tSalary\tperHRA\thouseRent\tnetSalary\n");
    while(1)
    {
        fscanf(fp,"%[^,],%d,%lf",names,&salary,&perHRA);
        //printf("%s earns $%d salary per minute",names,salary);
        houseRent = salary * perHRA;
        netSalary = salary - houseRent;
        fprintf(fpr,"%-25s %10d %10.2lf %10.2lf %13.2lf",names,salary,perHRA,houseRent,netSalary);
        if(feof(fp))
            break;
    }

    fclose(fp);
    fclose(fpr);
    return 0;
}
