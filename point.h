#include<iostream>
using namespace std;

/**
 * @file point.h
 * @author Neetu
 *
 * DESCRIPTION
 *
 * This is a header file which defines the point class.
 * Point class defines the functions which are used to generate 2-d points on a coordinate plane
 */

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

/** @brief Sets the x-coordinate 
 *  @param value is intialized double variable
 *  @return void
 */
void point::set_x(double value)
{
	this->x = value;
}

/** @brief Sets the y-coordinate 
 *  @param value is intialized double variable
 *  @return void
 */
void point::set_y(double value)
{
	this->y = value;
}

/** @brief Returns the x-coordinate 
 *  @return double
 */
double point::get_x()
{
	return this->x;
}

/** @brief Returns the y-coordinate 
 *  @return double
 */
double point::get_y()
{
	return this->y;
}

