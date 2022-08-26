
                                        //INCOMPLETE

#include<stdio.h>
#include<stdarg.h>
#include<limits.h>
void PrintArray(int [],int);                                    //(Array,size)
void MergeSort(int [],int,int);                                 //(Array,low,high)
void Merge(int [],int,int,int);                                 //(Array,low,mid,high)
int Start_Merging(int [],int [],int ,int ,int [],int );         //(Array1,Array2,size of Array1,size of Array2,Result Array,no.of data in array)
int Calculate_Size(char []);                                    //(Filename)
void Read_Data(int [],int ,char []);                            //(Array,size,Filename)


int main()
{
    //Creating the files
    {
        FILE *fp1,*fp2,*fp3,*fp4,*fp5,*file;
        fp1=fopen("A.txt","r");
        fp2=fopen("B.txt","r");
        fp3=fopen("C.txt","r");
        fp4=fopen("D.txt","r");
        fp5=fopen("E.txt","r");
        file=fopen("Sorted_Result.txt","w");
        if(fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL ||  fp5==NULL || file==NULL)
        {
            printf("\nUnable to open some file\nExiting\n");
            return 1;
        }
    }

    //Calculating Size of files
    {
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
    }

    //Reading Data of files
    {
        Read_Data(A,s1,string1);
        Read_Data(B,s2,string2);
        Read_Data(C,s3,string3);
        Read_Data(D,s4,string4);
        Read_Data(E,s5,string5);
    }

    //Printing the contents
    {
         int i;
        printf("Content of the file: ");
        printf("Array1: ");
        for(i=0;i<s1;printf("%d ",A[i]),i++);
        printf("\nArray2: ");
        for(i=0;i<s2;printf("%d ",B[i]),i++);
        printf("\nArray3: ");
        for(i=0;i<s3;printf("%d ",C[i]),i++);
        printf("\nArray4: ");
        for(i=0;i<s4;printf("%d ",D[i]),i++);
        printf("\nArray5: ");
        for(i=0;i<s5;printf("%d ",E[i]),i++);
    }

    //Optimal Merging

    int size=s1+s2+s3+s4+s5;
    int Sort[size];
    int flag=0;                             //To count no.of elements in Sort array
    int size_array[5];
    size_array[0]=s1;
    size_array[1]=s2;
    size_array[2]=s3;
    size_array[3]=s4;
    size_array[4]=s5;
    size_array[5]=INT_MAX;
    int min1,min2;
    while(1)
    {
    min1 = min_size(size_array[0],size_array[1],size_array[2],size_array[3],size_array[4],size_array[5]);
    size_array[min1]=-1;
    min2 = min_size(size_array[0],size_array[1],size_array[2],size_array[3],size_array[4],size_array[5]);
    size_array[min2]=-1;
    if(min1==0)
    {
        if(min2==1)
            size_array[min1]=Start_Merging(A,B,s1,s2,Sort,size);
        if(min2==2)
            size_array[min2]=Start_Merging(A,C,s1,s3,Sort,size);
        if(min2==3)
            size_array[min3]=Start_Merging(A,D,s1,s5,Sort,size);
        if(min2==4)
            size_array[min4]=Start_Merging(A,E,s1,s5,Sort,size);
        if(min2==5)
            size_array[min5]=Start_Merging(A,Sort,s1,size,Sort,size);
    }
    if(min1==1)
    {
        {
            if(min2==0)
                size_array[min0]=Start_Merging(B,A,s2,s1,Sort,size);
            if(min2==2)
                size_array[min2]=Start_Merging(B,C,s2,s3,Sort,size);
            if(min2==3)
                size_array[min3]=Start_Merging(B,D,s2,s4,Sort,size);
            if(min2==4)
                size_array[min4]=Start_Merging(B,E,s2,s5,Sort,size);
            if(min2==5)
                size_array[min5]=Start_Merging(B,Sort,s2,size,Sort,size);
        }
    }
    if(min1==2)
    {
        {
            if(min2==0)
                size_array[min0]=Start_Merging(C,A,s3,s1,Sort,size);
            if(min2==1)
                size_array[min1]=Start_Merging(C,B,s3,s2,Sort,size);
            if(min2==3)
                size_array[min3]=Start_Merging(C,D,s3,s4,Sort,size);
            if(min2==4)
                size_array[min4]=Start_Merging(C,E,s3,s5,Sort,size);
            if(min2==5)
                size_array[min5]=Start_Merging(C,Sort,s3,size,Sort,size);
        }
    }
    if(min1==3)
    {
        {
            if(min2==0)
                size_array[min0]=Start_Merging(D,A,s4,s1,Sort,size);
            if(min2==1)
                size_array[min1]=Start_Merging(D,B,s4,s2,Sort,size);
            if(min2==2)
                size_array[min2]=Start_Merging(D,C,s4,s3,Sort,size);
            if(min2==4)
                size_array[min4]=Start_Merging(D,E,s4,s5,Sort,size);
            if(min2==5)
                size_array[min5]=Start_Merging(D,Sort,s4,size,Sort,size);
        }
    }
    if(min1==4)
    {
        {
            if(min2==0)
                size_array[min0]=Start_Merging(E,A,s5,s1,Sort,size);
            if(min2==1)
                size_array[min1]=Start_Merging(E,B,s5,s2,Sort,size);
            if(min2==2)
                size_array[min2]=Start_Merging(E,C,s5,s3,Sort,size);
            if(min2==3)
                size_array[min3]=Start_Merging(E,D,s5,s4,Sort,size);
            if(min2==5)
                size_array[min5]=Start_Merging(E,Sort,s5,size,Sort,size);
        }
    }
    if(min1==5)
    {
        {
            if(min2==0)
                size_array[min0]=Start_Merging(Sort,A,size,s1,Sort,size);
            if(min2==1)
                size_array[min1]=Start_Merging(Sort,B,size,s2,Sort,size);
            if(min2==2)
                size_array[min2]=Start_Merging(Sort,C,size,s3,Sort,size);
            if(min2==3)
                size_array[min3]=Start_Merging(Sort,D,size,s4,Sort,size);
            if(min2==4)
                size_array[min4]=Start_Merging(Sort,E,flag,s5,Sort,size);
        }
    }

    size_array[5]=min1+min2;
    for(i=0;i<6;i++)
    {
        if(i!=-1))
            break;
    }
    if(i==6)
        break;
    }
    //Closing the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(file);

    return 0;
}

int min_size(int count, ...)
{
    va_list ap;
    va_start(ap,count);
    int i=0;
    int A[count];
    for(;i<count;i++)
    {
        A[i]=va_arg(ap,list);
    }
    va_end(ap);
    int min=A[0];
    int j=0;
    i=1;
    while(i<count)
    {
        if(A[i]<min)
        {
            j=i;
        }
    }

    return j;
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

    int size=0;
    char c=getc(fp);
    while(!feof(fp))
    {
        if(c=='\n')
            size++;
        c=getc(fp);
    }
    size++;
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

    fclose(fp);
}

void PrintArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}

int Start_Merging(int A[],int B[],int a,int b,int C[],int n )
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

