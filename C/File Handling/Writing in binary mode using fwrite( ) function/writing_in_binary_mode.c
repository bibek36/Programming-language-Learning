#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("file.txt","wb");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    double data[]={10.2,2.3,93.4,39.0};

    int nObject = fwrite((void *)data, sizeof(double), 4, fp);
    printf("\nTotal number of element written: %d\n",nObject);

    fclose(fp);
    return 0;
}
