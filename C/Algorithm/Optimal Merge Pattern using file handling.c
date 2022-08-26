#include<stdio.h>

void PrintArray(int [],int);                                    //(Array,size)
void MergeSort(int [],int,int);                                 //(Array,low,high)
void Merge(int [],int,int,int);                                 //(Array,low,mid,high)
int Start_Merging(int [],int [],int ,int );                     //(Array1,Array2,size of Array1,size of Array2)
int Calculate_Size(char []);                                     //(Filename)
void Read_Data(int [],int ,char []);                             //(Array,size,Filename)


int main()
{
    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*file;
    fp1=fopen("A.txt","r");
    fp2=fopen("B.txt","r");
    fp3=fopen("C.txt","r");
    fp4=fopen("D.txt","r");
    fp5=fopen("E.txt","r");
    file=fopen("Sorted_Result.txt","w");
    if(fp1==NULL || fp2=NULL || fp3==NULL || fp4==NULL ||  fp5==NULL || file==NULL)
    {
        printf("\nUnable to open some file\nExiting\n");
        return 1;
    }

    //Calculating Size of files
    char string1[]={"A.txt"};
    char string2[]={"B.txt"};
    char string3[]={"C.txt"};
    char string4[]={"D.txt"};
    char string5[]={"E.txt"};
    int s1=Calculate_Size(string1);
    int s2=Calculate_Size(string2);
    int s3=Calculate_Size(string3);
    int s4=Calculate_Size(string4);
    int s5=Calculate_Size(string5);
    int A[s1];
    int B[s2];
    int C[s3];
    int D[s4];
    int E[s5];

    //Reading Data of files
    Read_Data(A,s1,string1);
    Read_Data(B,s2,string2);
    Read_Data(C,s3,string3);
    Read_Data(D,s4,string4);
    Read_Data(E,s5,string5);

    //Printing the contents
    printf("Content of the file: ");
    printf("Array1: ");
    for(i=0;i<s1;printf("%d ",A[i]),i++);
    printf("\nArray2: ");
    for(i=0;i<s2;printf("%d ",B[i]),i++);
    printf("Array3: ");
    for(i=0;i<s3;printf("%d ",C[i]),i++);
    printf("Array4: ");
    for(i=0;i<s4;printf("%d ",D[i]),i++);
    printf("Array5: ");
    for(i=0;i<s5;printf("%d ",E[i]),i++);



    return 0;
}

int Calculate_Size(char file_name[])
{
    FILE *fp;
    fp=fopen(file_name,"r");
    if(fp==NULL)
    {
        printf("\nUnable to open some file\nExiting\n");
        return 1;
    }

    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    return size;
}

void Read_Data(int A[],int size,char file_name[])
{
    FILE *fp;
    fp=fopen(file_name,"r");
    if(fp==NULL)
    {
        printf("\nUnable to open some file\nExiting\n");
        return 1;
    }
    int i=0,num;
    while(fscanf(fp, "%d", &num) > 0)
    {
        A[i] = num;
        i++;
    }
    for(i=0;i<n;printf("%d ",A[i]),i++);

    fclose(fp);
}

void PrintArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}

int Start_Merging(int A[],int B[],int a,int b,int C[],int )
{
    int i=n;
    int s1=a+n;
    int s2=a+b+n;
    for(;i<s1;i++)
        C[i]=A[i];
    for(i=0;i<s2;i++)
        C[i]=B[i];
    MergeSort(C,0,s2);
    return s2;
}

void MergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

void Merge(int A[],int l,int m,int h)
{
    int i,j,k;
    int size=h-l+1;
    int B[size];
    i=l,j=m+1,k=0;
    while(i<=m && j<=h)
    {
        if(A[i]<=A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }

    for(;i<=m;i++)
        B[k++]=A[i];

    for(;j<=h;j++)
        B[k++]=A[j];

    printf("\n");
    PrintArray(B,size);
    printf("\n");

    for(i=0;i<size;i++)
    {
        A[l++]=B[i];
    }
}

