#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("file.txt","w");     //EXCLUSIVE Write Operation

    //Writing Uppercase characters in the file
    char ch;
    for(ch='A';ch<'Z';ch++)
        fputc(ch,fp);

    fclose(fp);


    fp = fopen("file.txt","a");     //EXCLUSIVE Append Operation

    //Writing Lowercase characters in the file
    for(ch='a';ch<'z';ch++)
        fputc(ch,fp);

    fclose(fp);

    return 0;

}
