#include<iostream>
#include<map>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include "point.h"
using namespace std;

/** @file    lsystem.h
 *  @author  Neetu 
 *  
 *  DESCRIPTION
 *  
 *  This is a header file that defines the class lsystem.
 *  class lsystem defines functions which read in the rules for 
 *  the lsystem pattern and generate the vector of vertices 
 *  which are used to plot the pattern using opengl. 
 *
*/

class lsystem{
	map<char,string> rules;
	string start, chain;
	int iterations;
	double angle,ang;
	vector<point*> vertices;
	stack<double> angles;
	stack<point> positions;
	void iterate();


	public:

	point start_point,cur_point, end_point ;
	void set_start(string start);
	void set_iterations(int n);
	void set_angle(double angle);
	void add_rule(char first,string second);
	string get_chain();
	vector<point* > get_vertices();
	int get_iterations();
	void print();
	double get_angle();
	void store_vertices(double angle);
	void draw_tree();
	void set_start_point(double x,double y);

};

point* create_point(double x,double y)
{
	    point* p = new point(x,y);
		return p;
}

/** 
  *   @brief  Sets the start token for the pattern to be generated   
  *  
  *   @param  'start' is the string variable
  *   @return void
  */ 
void lsystem::set_start(string start)
{
	this->start = start;
	chain = start;
	ang = -55.0;
}


/** 
  *   @brief  Sets the start point on the canvas   
  *  
  *   @param  x is an initialized double variable 
  *   @param  b is an initialized double variable 
  *   @return void
  */  
void lsystem:: set_start_point(double x,double y)
{
	this->cur_point.set_x(x);
	this->cur_point.set_y(y);
}

/** 
  *   @brief  Sets the number of iterations for which the pattern  
  *			  has to be repeated
  *
  *   @param  n is an initialized integer variable 
  *   @return void
  */  
void lsystem::set_iterations(int n)
{
	this->iterations = n;
}

/** 
  *   @brief  returns the preset value of the number of iterations.   
  *   @return int
  */  
int lsystem:: get_iterations()
{
	return this->iterations;
}

/** 
  *   @brief  Sets the rotation angle of the pattern.   
  *  
  *   @param  angle is an initialized double variable 
  *   @return void
  */  
void lsystem::set_angle(double angle)
{
	this->angle = angle;
}

/** 
  *   @brief  Returns the preset value of the rotation angle   
  *   @return double
  */  
double lsystem::get_angle()
{
	return this->angle;
}

/** 
  *   @brief  Adds rules for the expansion of the start token   
  *  
  *   @param  first is an initialized char variable 
  *   @param  second is an initialized string variable 
  *   @return void
  */  
void lsystem::add_rule(char first,string second)
{
	rules.insert(pair<char,string>(first,second));
}


/** 
  *   @brief  Prints the chain ( purely for debugging purposes ). 
  *   @return void
  */  
void lsystem::print()
{
	cout << chain << endl;
}

/** 
  *   @brief  Expands on the start token and the given rules to get the lsystem chain 
  *   @return void
  */  
void lsystem::draw_tree()
{
	int n = this->get_iterations();
	for(int i = 0; i < n ; i++)
	{
		string temp = "";
		for(int i = 0; i < chain.size(); i++)
		{
			if ( rules[chain[i]] != "" )
				temp += rules[chain[i]];
			else temp += chain[i];
		}
		chain = temp;
	}
}

/** 
  *   @brief  Converts degrees to radian 
  *  
  *   @param  angle is an initialized double variable 
  *   @return double
  */  
double rad(double angle)
{
	return angle * (M_PI/180);

}

/** 
  *   @brief  Swaps the values of two integer parameters.   
  *  
  *   @param  a is an initialized integer variable 
  *   @param  b is an initialized integer variable 
  *   @return void
  */  
string lsystem::get_chain()
{
	return this->chain;
}

double len = 0.02; 

//double len = 0.05;

/** 
  *   @brief  Stores the vertices as generated by the get_vertices() function
  *  
  *   @param  angle is an initialized double variable 
  *   @return void
  */  
void lsystem::store_vertices(double angle)
{
	double x = cur_point.get_x();
	double y = cur_point.get_y();

	end_point.set_x( x + (len)*cos(angle));
	end_point.set_y( y + (len)*sin(angle));

	vertices.push_back(create_point(x,y));
	vertices.push_back(create_point(end_point.get_x(), end_point.get_y()));

	cur_point.set_x(end_point.get_x());
	cur_point.set_y(end_point.get_y());
}

 
/** 
  *   @brief  Generates turtle string by iteratively expanding the start token   
  *   @return vector<point*>
  */  
vector<point* > lsystem::get_vertices() 
{
	this->draw_tree();
	string chain = this->get_chain();
	double angle = this->get_angle();
	for(int i = 0; i < chain.size(); i++)
	{
		switch(chain[i])
		{
			case '+':     /** Apply a positive rotatation about the X-axis of xrot degrees.*/
				ang += rad(angle);
				break;
			case '-':     /** Apply a negative rotatation about the X-axis of xrot degrees.*/
				ang -= rad(angle);
				break;
			case '[':     /** Push the current state of the turtle onto a pushdown stack.*/
				positions.push(cur_point);
				angles.push(ang);
				break;
			case ']':     /** Pop the state from the top of the turtle stack, and make it the current turtle stack.*/
				cur_point = positions.top();
				positions.pop();
				ang = angles.top();
				angles.pop();
				break;
			default:
				store_vertices(ang);
				break;
		}
	}
	return vertices;
}


