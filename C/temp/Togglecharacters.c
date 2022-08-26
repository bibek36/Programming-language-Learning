#include<stdio.h>
#include<string.h>
void Toggle_char(char *ptr)
{
    int i=0;
    for(;*(ptr+i)!='\0';i++)
    {
            if(*(ptr+i)>='A'&&*(ptr+i)<='Z')
                *(ptr+i)+=32;

            else if(*(ptr+i)>='a'&&*(ptr+i)<='z')
                *(ptr+i)-=32;
    }
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    Toggle_char(str);
    printf("\nThe Toggled string is: %s\n\n",str);

    return 0;
}
