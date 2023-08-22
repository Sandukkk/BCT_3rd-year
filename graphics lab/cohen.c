#include<stdio.h>
#include<graphics.h>
#include<conio.h>
static int LEFT = 1, RIGHT = 2, TOP = 8, 
BOTTOM = 4, xmin, ymin, xmax, ymax;
int getcode(int x, int y);
{
     int code = 0;
     if (y>ymax) code | = TOP;
     if (y<ymin) code | = BOTTOM;
     if (x<xmin) code | = LEFT; 
     if (x>xmax) code | = RIGHT; 
     return code;
}
int main()
{
    int i,x1,y1,x2,y2;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    printf("enter windows maximum and
    minimum values");
    scanf("%d%d%d%d",&xmax,&ymax,&xmin
    ,&ymin);
    printf("enter end points of the 
    line");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    getch();
    int outcode1 = getcode (x1, y1);
    int outcode2 = getcode (x2, y2);
    int accept = 0;
    while(1)
    {
        float m = (float)(y2-y1)/(x2-x1);
        if (outcode1 == 0 && outcode2 ==0)
        {
            accept = 1;
            break;
        }
        else if((outcode1 & outcode2)!= 0)
        {
            break;
        }
        else
        {
            int x,y,temp;

            if(outcode1 ==0)
                temp = outcode2;
            else 
                temp = outcode1;
            }
            if (temp & TOP)
            {
                x=x1+(ymax-y1)/m;
                y=ymax;
            }
            if (temp & BOTTOM)
            {
                x=x1+(ymin-y1)/m;
                y=ymin;
            }
            if (temp & RIGHT)
            {
                y=y1+(xmax-x1)*m;
                x=xmax;
            }
            if (temp & LEFT)
            {
                y=y1+(xmin-x1)*m;
                x=xmin;
            }

            if(temp==outcode1)
            {
            x1=x;
            y1=y;
            outcode1 = getcode (x1, y1);
            }
            else
            {
            x2 = x;
            y2 = y;
            outcode2 = getcode(x2,y2);
            }}}
            
        if(accept)
        {
            cleardevice();
            rectangle(xmin,ymin,xmax,ymax);
            line(x1,y1,x2,y2);
        }
        getch();
	closegraph();
	return 0;
}