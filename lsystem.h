#include<iostream>
#include<map>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include "point.h"
using namespace std;



class lsystem{
	map<char,string> rules;
	string start, chain;
	int iterations;
	double angle,gangle;
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

void lsystem::set_start(string start)
{
	this->start = start;
	chain = start;
	gangle = 45.0;
}

void lsystem:: set_start_point(double x,double y)
{
	this->cur_point.set_x(x);
	this->cur_point.set_y(y);
}

void lsystem::set_iterations(int n)
{
	this->iterations = n;
}

int lsystem:: get_iterations()
{
	return this->iterations;
}

void lsystem::set_angle(double angle)
{
	this->angle = angle;
}

double lsystem::get_angle()
{
	return this->angle;
}

void lsystem::add_rule(char first,string second)
{
	rules.insert(pair<char,string>(first,second));
}

void lsystem::print()
{
	cout << chain << endl;
}

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
//		print();
	}
}

double rad(double angle)
{
	return angle * (M_PI/180);

}

string lsystem::get_chain()
{
	return this->chain;
}

double len = 0.00999;
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

vector<point* > lsystem::get_vertices()
{
	this->draw_tree();
	string chain = this->get_chain();
	double angle = this->get_angle();
	for(int i = 0; i < chain.size(); i++)
	{
		switch(chain[i])
		{
			case '+':
				gangle += rad(angle);
				break;
			case '-':
				gangle -= rad(angle);
				break;
			case '[':
				positions.push(cur_point);
				angles.push(gangle);
				break;
			case ']':
				cur_point = positions.top();
				positions.pop();
				gangle = angles.top();
				angles.pop();
				break;
			default:
				store_vertices(gangle);
				break;
		}
	}
	return vertices;
}


