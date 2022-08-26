
#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("file.txt","r");     //EXCLUSIVE Reading Operation

    //Reading characters from the file
    //Prime Reading Method
    char ch;
    ch =  fgetc(fp);

    while(!feof(fp))
    {
        printf("%c",ch);
        ch = fgetc(fp);
    }

    fclose(fp);

    return 0;
}
