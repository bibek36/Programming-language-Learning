#include<stdio.h>
#define SIZE 80
int main()
{
    FILE *fp;
    fp = fopen("file.txt","r");     //EXCLUSIVE Reading Operation
    if(fp==NULL)
    {
        printf("Unable to open file");
        return 1;
    }
    //Reading Formatted data from text file using fscanf() function

    char names[SIZE];
    int salary;
    while(1)
    {
        fscanf(fp,"%[^,],%d",names,&salary);
        printf("%s earns $%d salary per minute",names,salary);
        if(feof(fp))
            break;
    }

    fclose(fp);

    return 0;
}
