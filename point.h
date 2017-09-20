#include<iostream>
using namespace std;

class point{
	double x;
	double y;

	public:

	point()
	{
		this->x = 0.0;
		this->y = 0.0;
	}

	point(double x,double y)
	{
		this->x = x;
		this->y = y;
	}

	void set_x(double value);
	void set_y(double value);
	double get_x();
	double get_y();
//	point* create_point(double x,double y);
};

void point::set_x(double value)
{
	this->x = value;
}

void point::set_y(double value)
{
	this->y = value;
}

double point::get_x()
{
	return this->x;
}

double point::get_y()
{
	return this->y;
}

