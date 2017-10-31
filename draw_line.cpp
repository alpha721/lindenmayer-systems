#include<stdio.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<time.h>

using namespace std;

/**@file draw_line.cpp
 * @author Neetu
 *
 * DESCRIPTION
 *
 * This file defines the midpoint line drawing algorithm
 * It takes in input of the coordinates from the command line 
 * and draws the line
 */
 


/** the coordinates of the end point of the line */
float X1,Y1,X2,Y2;

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


/**@brief gets the octant in which the line lies based on the coordinates provided 
  *@return int
*/
int get_octant() {
  int dy = Y2 - Y1;
  int dx = X2 - X1;

  double slope = dy / dx;
  if (0 <= slope && slope < 1) {
    if (X1 >= 0 && Y1 >= 0 && X2 >= 0 && Y2 >= 0) {
      return 1;
    } else if (X1 <= 0 && Y1 <= 0 && X2 <= 0 && Y2 <= 0) {
      return 5;
    }
  } else if (slope > -1 && slope < 0) {
    if (X1 <= 0 && Y1 >= 0 && X2 <= 0 && Y2 >= 0) {
      return 4;
    } else if (X1 >= 0 && Y1 <= 0 && X2 >= 0 && Y2 <= 0) {
      return 8;
    }
  } else if (slope >= 1) {
    if (X1 >= 0 && Y1 >= 0 && X2 >= 0 && Y2 >= 0) {
      return 2;
    } else if (X1 <= 0 && Y1 <= 0 && X2 <= 0 && Y2 <= 0) {
      return 6;
    }
  } else if (slope <= -1) {
    if (X1 <= 0 && Y1 >= 0 && X2 <= 0 && Y2 >= 0) {
      return 3;
    } else if (X1 >= 0 && Y1 <= 0 && X2 >= 0 && Y2 <= 0) {
      return 7;
    }
  } else {
    return 0;
  }
}

/** @brief plots the coordinates according to the octant 
  *        in which they lie 
  * @params octant is initialized integer variable
  *         x is intialized integer variable
  *         y is initialized integer variable
  * @return void
  */
void output(int octant, int x, int y) {
  switch (octant) {
    case 1:
      glVertex2d(round(x), round(y));
      break;
    case 2:
      glVertex2d(round(y), round(x));
      break;
    case 3:
      glVertex2d(round(-y), round(x));
      break;
    case 4:
      glVertex2d(round(-x), round(y));
      break;
    case 5:
      glVertex2d(round(-x), round(-y));
      break;
    case 6:
      glVertex2d(round(-y), round(-x));
      break;
    case 7:
      glVertex2d(round(y), round(-x));
      break;
    case 8:
      glVertex2d(round(x), round(-y));
      break;
    default:
      break;
  }
}

/** @brief the mid-point line drawing algorithm
  * @return void
  */
void draw_line(void) {
  clock_t t;
  t = clock();
  int dx = X2 - X1;
  int dy = Y2 - Y1;
  int octant = 0;  // represets line in multiple octants
  int temp;

  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3d(0, 0, 0);
  glBegin(GL_POINTS);
  /** Both initial and final point are same */
  if (dx == 0 && dy == 0) {
    glVertex2d(X1, Y1);  
    glEnd();
    glFlush();
    return;
  } 
  else if (dx == 0) /** The line is parallel to Y - axis */ 
  {
    int y_start = min(Y1, Y2);
    int y_end = max(Y1, Y2);
    while (y_start <= y_end) {
      glVertex2d(round(X1), round(y_start));
      y_start++;
    }
    glEnd();
    glFlush();
    return;
  }
  else if (dy == 0) /** The line is parallel to X- axis */ 
  {
    int x_start = min(X1, X2);
    int x_end = max(X1, X2);
    while (x_start <= x_end) {
      glVertex2d(round(x_start), round(Y1));
      x_start++;
    }
    glEnd();
    glFlush();
    return;
  }
  else /* get the octant in which the line lies */
  {
    octant = get_octant();
  }

  /** adjust the coordinates for the line to lie in the correct octant */
  switch (octant) {
    case 0:
      printf("Line lies in multiple octants");
      glEnd();
      glFlush();
      return;
    case 1:
      break;
    case 2:
      temp = X2;
      X2 = Y2;
      Y2 = temp;

      temp = X1;
      X1 = Y1;
      Y1 = temp;
      break;
    case 3:
      temp = X2;
      X2 = Y2;
      Y2 = -temp;

      temp = X1;
      X1 = Y1;
      Y1 = -temp;
      break;
    case 4:
      X1 = -X1;
      X2 = -X2;
      break;
    case 5:
      X1 = -X1;
      X2 = -X2;

      Y1 = -Y1;
      Y2 = -Y2;
      break;
    case 6:
      temp = X2;
      X2 = -Y2;
      Y2 = -temp;

      temp = X1;
      X1 = -Y1;
      Y1 = -temp;
      break;
    case 7:
      temp = X2;
      X2 = -Y2;
      Y2 = temp;

      temp = X1;
      X1 = -Y1;
      Y1 = temp;
      break;
    case 8:
      Y1 = -Y1;
      Y2 = -Y2;
      break;

    default:
      break;
  }

  /** adjust the final and initial points */
  if (X1 > X2) {
    int temp = X2;
    X2 = X1;
    X1 = temp;

    temp = Y2;
    Y2 = Y1;
    Y1 = temp;
  }

  /** Mid-point line drawing algorithm */
  int x = X1, y = Y1;
  dx = X2 - X1;
  dy = Y2 - Y1;
  int dE = 2 * dy;
  int dNE = 2 * (dy - dx);
  int d = 2 * dy - dx;

  output(octant, x, y);

  while (x < X2)
  {
    if (d <= 0)
    {
      d += dE;
    } 
    else 
    {
      d += dNE;
      y += 1;
    }
    output(octant, x, y);
    x++;
  }
  t = clock() - t;
  cout << "Time taken for execution = " << (((float)t)/CLOCKS_PER_SEC)*1000 << " ms"  << endl;
  glEnd();
  glFlush();
}

/** @brief main function
  * @return int
  */
int main(int argc,char** argv)
{
	cout << "x0 : " ; cin >> X1;
	cout << "y0 : " ; cin >> Y1;
	cout << "x1 : " ; cin >> X2;
	cout << "y1 : " ; cin >> Y2;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithm");
	glutDisplayFunc(draw_line);
	init ();
	glutMainLoop();
}
	

