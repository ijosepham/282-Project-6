#include "pch.h"
#include "Point.h"

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(long newX, long newY)
{
	x = newX;
	y = newY;
}

void Point::setX(long newX)
{
	x = newX;
}

void Point::setY(long newY)
{
	y = newY;
}

long Point::getX()
{
	return x;
}

long Point::getY()
{
	return y;
}

ostream& operator<<(ostream& out, Point  & p) 
{
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

istream& operator>>(istream& in, Point  & p)
{
	cout << "Enter a value for x: ";
	in >> p.x;
	cout << endl << "Enter a value for y: ";
	in >> p.y;
	return in;
}

Point::~Point()
{
	// this is a destructor
}
