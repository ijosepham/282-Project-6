#include "pch.h"
#include "Point.h"

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double newX, double newY)
{
	x = newX;
	y = newY;
}

void Point::setX(double newX)
{
	x = newX;
}

void Point::setY(double newY)
{
	y = newY;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

ostream& operator<<(ostream& out, const Point& p) 
{
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

istream& operator>>(istream& in, Point  & p)
{
	cout << "Enter a value for x: ";
	in >> p.x;
	cout << "Enter a value for y: ";
	in >> p.y;
	return in;
}

Point::~Point()
{
	// this is a destructor
}
