

                                                /*INCOMPLETE*/

#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    int sum=1,count=0,i;
    do
    {
        i=n%10;
        n=n/10;
        sum*=i;
        count++;
    }while(1);
    return 0;
}
