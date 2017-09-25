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

float ax,ay,bx,by;
void draw_line(float ax, float ay, float bx, float by);

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
	draw_line(ax,ay,bx,by);
	glFlush();
}

/*===========================================================
 * Mid-pint line drawing algorithm
 * ==========================================================*/


/* function to draw line */

 void draw_line (float ax, float ay, float bx, float by)  //ax,ay =minitial point, bx,by = final point
  {  
  //to know slope of line
  int dx = abs (bx - ax);  
  int dy = abs (by - ay);  
  int x, y;  
  
  //slope<1 line below
  if (dx >= dy)  
  {  
   //updating factor to check position of next mid point wrt line
   int d = 2*dy-dx;  
   int ds = 2*dy;  
   int dt = 2*(dy-dx);  
   //check if it has reached till final x limit
       if (ax < bx)   
       {  
            x = ax;  
            y = ay;  
       }  
        else  
        {   
             x = bx;  
             y = by;  
             bx = ax;  
             by = ay;  
        }  
        //plot function to mark pixel
       plot(x, y);
         
       //loop to run till final x
   while (x < bx)  
   {  
        if (d < 0)  
       d += ds;  
       else {  
       //check it if has reached till final y limit or not
             if (y < by) 
             {  
             y++;  
              d += dt;  
             }   
             else {  
             y--;  
             d += dt;  
            }  
           }  
  x++;  
  //plot function to mark pixel
       plot(x, y);  
      }  
      }  
      // slope > 1 line below
      else {   
            int d = 2*dx-dy;  
            int ds = 2*dx;  
            int dt = 2*(dx-dy);  
            //to check if reached till final y limit or not
            if (ay < by) {  
            x = ax;  
            y = ay;  
             }  
             else {   
             x = bx;  
             y = by;  
             by = ay;  
             bx = ax;  
            }  
            //plot function to mark pixel
            plot(x, y);
            //loop to run till final y
        while (y < by)  
        {  
              if (d < 0)  
                 d += ds;  
              else {  
                      if (x > bx){  
                      x--;  
                      d += dt;  
                  } else {  
                      x++;  
                      d += dt;  
                   }  
             }  
             y++;  
             //plot function to mark pixel
              plot(x, y);  
        }  
       }  
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
	

