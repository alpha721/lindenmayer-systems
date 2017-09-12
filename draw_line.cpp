#include<stdio.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>

using namespace std;

/*		OCTANTS
 *
 * \	III	|     /
 *	   \    | II /
 *	IV	\	|   /
 *		 \	|  /   I
 *		  \	| /  
 *_________\|/____________
 *		   /|\
 *		  /	| \	VIII
 *	V	 /	|  \
 *		/	|   \
 *	   /	|    \
 *	  /	VI	| VII \
 *
*/

/*=========================================================
 * Initialization
 *=========================================================*/

int ax,ay,bx,by;
void draw_line();

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0); // set display-window background color - white
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
}

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);			// set line color
	glPointSize(4.0);				// thickness of line
	draw_line();
	glFlush();
}

/*===========================================================
 * Mid-pint line drawing algorithm
 * ==========================================================*/

void draw_line()
{
	int dx = abs(bx - ax);
	int dy = abs(by - ay);
	int de = 2* dy;
	int dne = 2* ( dy - dx);
	int d = 2*dy - dx;
	int x = ax;
	int y = ay;
	int m = (by - ay)/(bx - ax);

	/* First Octant */
	
//	if ( m > 0 && m < 1)
//	{
		plot(x,y);
		while ( x < bx)
		{
			if ( d < 0)
				d += de;
			else 
			{
				d += dne;
				y++;
			}
			x++;
			plot(x,y);
		}
	//}
}

int main(int argc,char** argv)
{
	cout << "x0 : " ; cin >> ax;
	cout << "y0 : " ; cin >> ay;
	cout << "x1 : " ; cin >> bx;
	cout << "y1 : " ; cin >> by;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithm");
	glutDisplayFunc(display);
	init ();
	glutMainLoop();
}
	

