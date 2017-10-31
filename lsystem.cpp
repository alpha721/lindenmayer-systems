#include<iostream>
#include<GL/glut.h>
#include<time.h>
#include "lsystem.h"
//#include "draw_line.h"

using namespace std;


vector<point*> vertices; /**  Vertices obtained by running the get_vertices() function in lsystem.h */

/** displays the pattern generated */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3f,1.0f,0.3f);
	for(int i = 0; i < vertices.size()/2; i++)
	{

    /** drawing lines using vertices obtained */
		glBegin(GL_LINES);
			glVertex2d(vertices[i*2]->get_x(), vertices[i*2]->get_y());
			glVertex2d(vertices[i*2 + 1]->get_x(), vertices[i*2 + 1]->get_y());
		glEnd();
	}
}


int main(int argc,char** argv)
{
	clock_t t;
	t = clock();
	lsystem l;

	// Uncomment one of the test cases to run them and leave the rest of them commented
	

	// Test case 1 :
	l.set_start("F");
	l.add_rule('F',"F[+F]F[-F][F]");
	l.set_iterations(5);
	l.set_angle(20);
	l.set_start_point(0,-0.75);
		
	// Test case 2 : (uncomment to run)
		
/*	   l.set_start("F");
	   l.add_rule('F',"FF-[-F+F+F]+[+F-F-F]");
	   l.set_iterations(4);
	   l.set_angle(22.5);
	   l.set_start_point(0,-0.75);
*/	 
	 
		
//	 Test case 3 : (uncomment to run)
	
	
/*	  l.set_start("F");
	   l.add_rule('F',"F[+F]F[-F]F");
	   l.set_iterations(5);
	   l.set_angle(25.7);
	   l.set_start_point(0,-0.75);
	 
*/	 
	     
		
	// Test case 4 : (uncomment to run)
	
	
/*	  l.set_start("X");
	   l.add_rule('X',"F[+X][-X]FX");
	   l.add_rule('F',"FF");
	   l.set_iterations(7);
	   l.set_angle(25.7);
	   l.set_start_point(0,-0.75);
*/	 
	 

	glutInit(&argc,argv);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("l-system");
	
	vertices = l.get_vertices();
	t = clock() - t;
	cout << "Time taken for execution = " << (((float)t)/CLOCKS_PER_SEC)* 1000 << " ms" << endl;
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
