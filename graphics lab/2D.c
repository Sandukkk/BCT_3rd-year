#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

struct Triangle{
	int x1, y1;
	int x2, y2; 
	int x3, y3 ;
};

void translation(struct Triangle tri){
	struct Triangle temp_tri;
	int tx = 40, ty = 40 ;
	int trans_vect[3][3] = 
 {1,0,tx,0,1,ty,0,0,1 };

	temp_tri.x1 = trans_vect[0][0]*
 tri.x1 + trans_vect[0][1]*tri.y1 +
 trans_vect[0][2]*1;
 
	temp_tri.y1 = trans_vect[1][0]* 
 tri.x1 + trans_vect[1][1]*tri.y1 +  
 trans_vect[1][2]*1;
 
	temp_tri.x2 = trans_vect[0][0]*
 tri.x2 + trans_vect[0][1]*tri.y2 +
 trans_vect[0][2]*1;
 
	temp_tri.y2 = trans_vect[1][0]*
 tri.x2 + trans_vect[1][1]*tri.y2 +
 trans_vect[1][2]*1;
 
        temp_tri.x3 = trans_vect[0][0]* 
 tri.x3 + trans_vect[0][1]*tri.y3 + 
 trans_vect[0][2]*1;
 
	temp_tri.y3 = trans_vect[1][0]*
 tri.x3 + trans_vect[1][1]*tri.y3 +
 trans_vect[1][2]*1;


	printf("%s","Translation");
	setcolor(RED);
	line(temp_tri.x1,temp_tri.y1,
 temp_tri.x2, temp_tri.y2 );
	
 line(temp_tri.x2,temp_tri.y2,
 temp_tri.x3, temp_tri.y3 );
	
 line(temp_tri.x3,temp_tri.y3,
 
 temp_tri.x1, temp_tri.y1 );

}

void scaling(struct Triangle tri){
	struct Triangle temp_tri;
	int sx = 2, sy = 3 ;
	int trans_vect[3][3] = 
 
 {sx,0,0,0,sy,0,0,0,1 };


	temp_tri.x1 = trans_vect[0][0]*
 (tri.x1-320) + trans_vect[0][1]*
 (240-tri.y1)  + trans_vect[0][2]*1;

 temp_tri.y1 = trans_vect[1][0]* 
 (tri.x1-320) + trans_vect[1][1]*
 (240-tri.y1) + trans_vect[1][2]*1;

	temp_tri.x2 = trans_vect[0][0]* 
 (tri.x2-320) + trans_vect[0][1]*
 (240-tri.y2) + trans_vect[0][2]*1;
 
	temp_tri.y2 = trans_vect[1][0]* 
 (tri.x2-320) + trans_vect[1][1]*
 (240-tri.y2) + trans_vect[1][2]*1;

	temp_tri.x3 = trans_vect[0][0]*
 (tri.x3-320) + trans_vect[0][1]*
 (240-tri.y3)+ trans_vect[0][2]*1;
 
	temp_tri.y3 = trans_vect[1][0]* 
 (tri.x3-320) + trans_vect[1][1]*
 (240-tri.y3)+ trans_vect[1][2]*1;

	temp_tri.x1 += 320;
	temp_tri.y1 += 240;

	temp_tri.x2 += 320;
	temp_tri.y2 += 240;

	temp_tri.x3 += 320;
	temp_tri.y3 += 240;

	printf("%s","\nScaling");

	setcolor(BLUE);
	line(temp_tri.x1,temp_tri.y1, 
 temp_tri.x2, temp_tri.y2 );
	line(temp_tri.x2,temp_tri.y2,
 temp_tri.x3, temp_tri.y3 );
	line(temp_tri.x3,temp_tri.y3,
 temp_tri.x1, temp_tri.y1 );

}

void rotation(struct Triangle tri){
	struct Triangle temp_tri;
	int theta = M_PI/4;
	int a00 = cos(theta), a01= 
 -sin(theta) , a10=sin(theta), a11= 
 cos(theta) ;

	int trans_vect[3][3] = 
 {a00,a01,0,a10,a11,0,0,0,1 };


	temp_tri.x1 = trans_vect[0][0]*
 
 (tri.x1-320) + trans_vect[0][1]*
 (240-tri.y1) + trans_vect[0][2]*1;
	temp_tri.y1 = trans_vect[1][0]*
 
 (tri.x1-320) + trans_vect[1][1]*
 (240-tri.y1)+ trans_vect[1][2]*1;

	temp_tri.x2 = trans_vect[0][0]*
 
 (tri.x2-320) + trans_vect[0][1]*
 (240-tri.y2) + trans_vect[0][2]*1;
	temp_tri.y2 = trans_vect[1][0]*
 
 (tri.x2-320) + trans_vect[1][1]*
 (240-tri.y2) + trans_vect[1][2]*1;

	temp_tri.x3 = trans_vect[0][0]*
 
 (tri.x3-320) + trans_vect[0][1]*
 (240-tri.y3)  + trans_vect[0][2]*1;
	temp_tri.y3 = trans_vect[1][0]*
 
 (tri.x3-320) + trans_vect[1][1]*
 (240-tri.y3) + trans_vect[1][2]*1;


	temp_tri.x1 += 320;
	temp_tri.y1 += 240;

	temp_tri.x2 += 320;
	temp_tri.y2 += 240;

	temp_tri.x3 += 320;
	temp_tri.y3 += 240;

	printf("%s\n","\nRotation");
	setcolor(GREEN);
	line(temp_tri.x1,temp_tri.y1,
 
 temp_tri.x2, temp_tri.y2 );
	line(temp_tri.x2,temp_tri.y2,
 
 temp_tri.x3, temp_tri.y3 );
	line(temp_tri.x3,temp_tri.y3,
 
 temp_tri.x1, temp_tri.y1 );

}

void reflection_x(struct Triangle tri){
	struct Triangle temp_tri;

	int trans_vect[3][3] = 
 {0,1,0,1,0,0,0,0,1}; 


	temp_tri.x1 = trans_vect[0][0]*
 (tri.x1-320) + trans_vect[0][1]*
 (240-tri.y1) + trans_vect[0][2]*1;
	temp_tri.y1 = trans_vect[1][0]*
 (tri.x1-320) + trans_vect[1][1]*
 (240-tri.y1) + trans_vect[1][2]*1;

	temp_tri.x2 = trans_vect[0][0]*
 (tri.x2-320) + trans_vect[0][1]*
 (240-tri.y2) + trans_vect[0][2]*1;
	temp_tri.y2 = trans_vect[1][0]*
 (tri.x2-320) + trans_vect[1][1]*
 (240-tri.y2) + trans_vect[1][2]*1;

	temp_tri.x3 = trans_vect[0][0]*
 (tri.x3-320) + trans_vect[0][1]*
 (240-tri.y3) + trans_vect[0][2]*1;
	temp_tri.y3 = trans_vect[1][0]*
 (tri.x3-320) + trans_vect[1][1]*
 (240-tri.y3) + trans_vect[1][2]*1;


	temp_tri.x1 += 320;
	temp_tri.y1 = 240-temp_tri.y1;

	temp_tri.x2 += 320;
	temp_tri.y2 = 240-temp_tri.y2;

	temp_tri.x3 += 320;
	temp_tri.y3 = 240 - temp_tri.y3;

	printf("%s\n","Reflection about
 y = x");
	setcolor(GREEN);
	line(temp_tri.x1,temp_tri.y1,
 temp_tri.x2, temp_tri.y2 );
	line(temp_tri.x2,temp_tri.y2,
 temp_tri.x3, temp_tri.y3 );
	line(temp_tri.x3,temp_tri.y3,
 temp_tri.x1, temp_tri.y1 );

}

void reflection_y(struct Triangle tri){
	struct Triangle temp_tri;

	int trans_vect[3][3] = 
 {0,-1,0,-1,0,0,0,0,1}; 


	temp_tri.x1 = trans_vect[0][0]*
 (tri.x1-320) + trans_vect[0][1]*
 (240-tri.y1) + trans_vect[0][2]*1;
 
	temp_tri.y1 = trans_vect[1][0]*
 (tri.x1-320) + trans_vect[1][1]*
 (240-tri.y1) + trans_vect[1][2]*1;

	temp_tri.x2 = trans_vect[0][0]*
 (tri.x2-320) + trans_vect[0][1]*
 (240-tri.y2) + trans_vect[0][2]*1;
 
	temp_tri.y2 = trans_vect[1][0]*
 (tri.x2-320) + trans_vect[1][1]*
 (240-tri.y2) + trans_vect[1][2]*1;

	temp_tri.x3 = trans_vect[0][0]*
 (tri.x3-320) + trans_vect[0][1]*
 (240-tri.y3) + trans_vect[0][2]*1;
 
	temp_tri.y3 = trans_vect[1][0]*
 (tri.x3-320) + trans_vect[1][1]*
 (240-tri.y3) + trans_vect[1][2]*1;


	temp_tri.x1 += 320;
	temp_tri.y1 = 240-temp_tri.y1;

	temp_tri.x2 += 320;
	temp_tri.y2 = 240-temp_tri.y2;

	temp_tri.x3 += 320;
	temp_tri.y3 = 240 - temp_tri.y3;

	printf("%s\n","Reflection about 
 y = -x ");
	setcolor(GREEN);
	line(temp_tri.x1,temp_tri.y1,
 temp_tri.x2, temp_tri.y2 );
	line(temp_tri.x2,temp_tri.y2,
 temp_tri.x3, temp_tri.y3 );
	line(temp_tri.x3,temp_tri.y3,
 temp_tri.x1, temp_tri.y1 );

}


int main()
{
	struct Triangle tri;
	struct Triangle temp;

	int X, Y;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3
 \\bgi");

	tri.x1 = 340;
	tri.y1 = 190;
	tri.x2 = 350;
	tri.y2 = 160;
	tri.x3 = 370;
	tri.y3 = 180;

    line(320,0,320,480);
    line(0,240,640,240);

	line(tri.x1,tri.y1,tri.x2,tri.y2);
	line(tri.x2,tri.y2,tri.x3,tri.y3);
	line(tri.x3,tri.y3,tri.x1,tri.y1);

	delay(2000);
	
	translation(tri);

	delay(2000);

	scaling(tri);

	delay(2000);

	rotation(tri);

	delay(2000);

    reflection_x(tri);

	delay(2000);
	
    reflection_y(tri);

    getch(); 
	closegraph();
    return 0;
}
     