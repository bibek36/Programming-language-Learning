#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("file.txt","rb");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    double data[5];

    int nObject = fread((void *)data, sizeof(double), 4, fp);
    printf("\nTotal number of element Read: %d\n",nObject);
    printf("Content of binary file: ");
    int i;
    for(i=0;i<4;i++)
        printf("%10.2lf",data[i]);
    fclose(fp);
    return 0;
}
