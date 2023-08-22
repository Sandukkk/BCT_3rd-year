


    #include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#include<dos.h>
using namespace std;
int main()
{
	int gd=DETECT,gm;
	int x1,y1,y2,x2,xincr,
        yincr,dx,dy,steps;
	initgraph(&gd,&gm," ");
	cout<<"Enter the value of x1,y1:";
	cin>>x1>>y1;
	cout<<"Enter the value of x2,y2:";
	cin>>x2>>y2;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
	steps=abs(dx);
	else
	steps=abs(dy);
	xincr=dx/steps;
	yincr=dy/steps;
	for(int i=0;i<steps;i++){
		putpixel(x1,y1,3);
		x1=x1+xincr;
		y1=y1+yincr;
		delay(50);
	}
	getch();
	closegraph();
	return 0;
}