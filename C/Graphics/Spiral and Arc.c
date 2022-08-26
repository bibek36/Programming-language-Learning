#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
int main()
{
    int i,gd=DETECT,gm;
    initgraph(&gd,&gm,"..\\bgi");

    for(i=0;i<1000 && !kbhit(); i++)
    {
        arc(getmaxx()/2,getmaxy()/2,0+i,90+i,i/10);
        delay(10);
    }

    return 0;
}
