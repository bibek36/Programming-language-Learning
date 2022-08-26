

                                            //Not Working
                                            //float is not working


#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>
double sum(char *format,...)
{
    int i;
    va_list ap;
    va_start(ap,format);
    double s=0;
    for(i=0;i<strlen(format);i++)
    {
        char ch=format[i];
        switch(ch)
        {
            case 'i':   s+=va_arg(ap,int);
                        break;
            case 'd':   s+=va_arg(ap,double);
                        break;
            case 'f':   s+=va_arg(ap,float);
                        break;
            default:    printf("\nInvalid format\nExiting program%d\n",i);
                        exit(1);
        }
        printf("%c,\t%lf\n",ch,s);
    }
    va_end(ap);
    return s;
}
int main()
{
        double k=sum("iddfii",54,85.5,4.2,24.2,03,5);
        printf("Sum: %.4lf",k);
        return 0;
}
