#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <math.h>

void ellipse(int x, int y, int a, int b)
{

int x0 = 0;
int y0 = b;
int p10 = b*b - a*a*b + 1/4*a*a;

while (1)
{
    putpixel(x + x0, y + y0, 5);
	putpixel(x - x0, y + y0, 5);
	putpixel(x + x0, y - y0, 5);
	putpixel(x - x0, y - y0, 5);

	x0 += 1;
	if (p10 < 0)
	{
		y0 = y0;
		p10 += 2*b*b*x0 + b*b;
	}
	else
	{
      y0 -= 1;
      p10 += 2*b*b*x0 - 2*a*a*y0 + b*b;
	}
	if (2*b*b*x0 > 2*a*a*y0)
	{
		break;
	}
	}
        int p20 = a*a - a*b*b + b*b / 4;

	x0 = a;
	y0 = 0;
	while (1)
	{
	putpixel(x + x0, y + y0, 5);
	putpixel(x - x0, y + y0, 5);
	putpixel(x + x0, y - y0, 5);
	putpixel(x - x0, y - y0, 5);	
       y0 += 1;
	if (p20 < 0)
	{
	x0 = x0;
	p20 += 2 * a * a * y0 + a * a;
	}
	else
	{
        x0 -= 1;
	p20 += 2*a*a*y0-2*b*b*x0+a*a;
	}
	if (2*a*a*y0 > 2*b*b*x0)
	{
	break;
	}
	}
      }

int main()
{
    int h, k, a, b;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    printf("Enter the center and intercept 
    of ellipse: ");
    scanf("%d%d%d%d", &h, &k, &a, &b );
    ellipse(h, k, a, b );
    getch();
    closegraph();
    return 0;
}