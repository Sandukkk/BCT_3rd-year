#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>


int main()
{

    int h, k ,r ; 
    int p0 , x0 , y0 ;

    int gd = DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    printf("Enter the center and radius:");
    scanf("%d%d%d", &h, &k, &r);

    p0 = 1-r ;
    x0 = 0;
    y0=r;

    while(x0<=y0){
       putpixel(h + x0, k + y0, 5);
       putpixel(h - x0, k + y0, 5);
       putpixel(h + x0, k - y0, 5);
       putpixel(h - x0, k - y0, 5);
       putpixel(h + y0, k + x0, 5);
       putpixel(h - y0, k + x0, 5);
       putpixel(h + y0, k - x0, 5);
       putpixel(h - y0, k - x0, 5);

        if (p0 <= 0){
            x0 = x0 + 1;
            y0 = y0 ;
            p0 = p0 +2*x0 + 1 ;
        }
        else{
            x0 = x0 + 1 ;
            y0 = y0 -1 ;
            p0 =p0 + 2*x0 - 2*y0 +1 ;
        }

    }
       

    getch(); 
	closegraph();
    return 0;
}