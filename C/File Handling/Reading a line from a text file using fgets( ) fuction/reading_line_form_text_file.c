#include<stdio.h>
#define SIZE 80
int main()
{
    FILE *fp;
    fp = fopen("file.txt","r");     //EXCLUSIVE Reading Operation

    //Reading characters from the file line by line

    char names[SIZE];
    while(1)
    {
        fgets(names,SIZE,fp);
        printf("%s",names);
        if(feof(fp))
            break;
    }

    fclose(fp);

    return 0;
}
