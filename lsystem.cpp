#include<iostream>
#include<GL/glut.h>
#include "lsystem.h"

using namespace std;

vector<point*> vertices;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3f,1.0f,0.3f);
	for(int i = 0; i < vertices.size()/2; i++)
	{
		glBegin(GL_LINES);
			glVertex2d(vertices[i*2]->get_x(), vertices[i*2]->get_y());
			glVertex2d(vertices[i*2 + 1]->get_x(), vertices[i*2 + 1]->get_y());
		glEnd();
	}
//	glFlush();
}


int main(int argc,char** argv)
{
	lsystem l;
	l.set_start("F");
	l.add_rule('F',"FF-[-F+F+F]+[+F-F-F]");
	l.set_iterations(4);
	l.set_angle(22.5);
	l.set_start_point(0,0);
		
	glutInit(&argc,argv);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("l-system");
	
	vertices = l.get_vertices();
/*	for(int i = 0; i < vertices.size(); i++)
	{
		cout << "(" << vertices[i*2]->get_x() << "," << vertices[i*2]->get_y() << ")   " ;
		cout << "(" << vertices[i*2 + 1]->get_x() << "," << vertices[i*2 + 1]->get_y() << ")" << endl;
	}*/
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
/*int main()
{
	lsystem l;
	l.set_start("A");
	l.add_rule('A',"AB");
	l.add_rule('B',"A");
	l.set_iterations(5);
	l.draw_tree();
	return 0;
}
*/
