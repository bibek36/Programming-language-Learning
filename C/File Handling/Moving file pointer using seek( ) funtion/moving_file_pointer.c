#include<stdio.h>
int main()
{

    FILE *fp;
    double val;
    fp = fopen("file.txt","rb");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    fseek(fp,2*sizeof(double),SEEK_SET);
    fread((void *)&val,sizeof(double),1,fp);
    printf("3rd element: %lf\n",val);

    fseek(fp,-1*sizeof(double),SEEK_END);
    fread((void *)&val,sizeof(double),1,fp);
    printf("Last element: %lf\n",val);

    fseek(fp,1*sizeof(double),SEEK_SET);
    fread((void *)&val,sizeof(double),1,fp);
    printf("2nd element: %lf",val);

    fclose(fp);
    return 0;
}
