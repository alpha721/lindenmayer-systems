#include<iostream>
#include<GL/glut.h>
#include<stdio.h>
#include<time.h>

using namespace std;

/**@file draw_circle.cpp
 * @author Neetu
 *
 * DESCRIPTION
 *
 * This file defines the mid-point circle drawing algorithm.
 * It takes in the centre coordinates and the radius of the circle
 * from the command line and draws the circle using opengl
 */


/** center coordinates of circle ( x-coordinate : h , y-coordinate : k) */
int h,k;	
/**	radius of circle */
int r;

		
void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + h, y + k);
	glEnd();
}

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0) ; /** set display-window background color to white */
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

/** @brief mid-point circle drawing algorithm
  * @return void
  */
void draw_circle()
{
	clock_t t;
	t = clock();
	int x = 0;
	int y = r;
	int d = 1 - r;		/** decision variable */
	int de = 3;			/** delta E */
	int dse = 5 - 2*r;	/** delta SE */

	plot(x,y);

	while( y > x)
	{
		if ( d <= 0 )	/** Select East */
		{
			d += de;
			de += 2;
			dse += 2;
		}
		else
		{
			d += dse;	/** Select South-East */
			de += 2;
			dse += 4;
			y--;
		}
		x++;
		/**plot the coordinates in all the octants based on symmetry */
		plot(x,y);
		plot(x,-y);
		plot(-x,y);
		plot(-x,-y);
		plot(y,x);
		plot(-y,x);
		plot(y,-x);
		plot(-y,-x);
	}
	t = clock() - t;
	cout << "Time taken for execution = " << (((float)t)/CLOCKS_PER_SEC)*1000 << " ms" << endl;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);
	draw_circle();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "enter center coordinates : " << endl;
	cout << "x : " ; cin >> h ;
	cout << "y : " ; cin >> k ;
	cout << "enter radius : " ; cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Midpoint Circle Drawing Alogrithm");
	glutDisplayFunc(display);
	init ();
	glutMainLoop();
	return 0;
}



