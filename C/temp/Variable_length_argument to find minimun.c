#include<stdio.h>
#include<stdarg.h>
int min(int count,...)
{
    int a,i,min;
    va_list ap;
    va_start(ap,count);
    min=va_arg(ap,int);
    for(i=1;i<=count;i++)
    {
        if((a=va_arg(ap,int))<min)
        min=a;
    }
    va_end(ap);

    return min;
}

int main()
{
    int k=min(6,54,85,68,24,03,56);
    printf("Min:%d \n",k);
    return 0;
}
