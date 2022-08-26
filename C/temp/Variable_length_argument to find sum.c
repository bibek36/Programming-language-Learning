#include<stdio.h>
#include<stdarg.h>
int sum(int count,...)
{
    int i;
    va_list ap;
    va_start(ap,count);
    int sum=0;
    for(i=1;i<=count;i++)\
    {
        sum+=va_arg(ap,int);
    }
    va_end(ap);
    return sum;
}
int main()
{
        int k=sum(6,54,85,68,24,03,56);
        printf("Sum: %d",k);
        return 0;
}
