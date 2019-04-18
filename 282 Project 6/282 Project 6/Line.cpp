#include "pch.h"
#include "Line.h"


Line::Line()
{
	p1 = Point();
	p2 = Point();
}

Line::Line(Point newP1, Point newP2)
{
	p1 = newP1;
	p2 = newP2;
}

Line::Line(double x1, double y1, double x2, double y2) 
{
	p1.setX(x1);
	p1.setY(y1);
	p2.setX(x2);
	p2.setY(y2);
}

// setters
void Line::setP1(Point newP1)
{
	p1 = newP1;
}

void Line::setP2(Point newP2)
{
	p2 = newP2;
}

void Line::setP1(double x, double y)
{
	p1.setX(x);
	p1.setY(y);
}

void Line::setP2(double x, double y)
{
	p2.setX(x);
	p2.setY(y);
}


// getters
Point Line::getP1()
{
	return p1;
}

Point Line::getP2()
{
	return p2;
}


// friend cin/cout
ostream& operator<<(ostream& out, const Line& line)
{	
	out << "Point A: " << line.p1 << endl;
	out << "Point B: " << line.p2 << endl;
	out << "Line: " << line.a << "x + " << line.b << "y = " << line.c << endl;
	return out;
}

istream& operator>>(istream& in, Line& line)
{
	cout << "Point A: " << endl;
	in >> line.p1;
	cout << endl << "Point B: " << endl;
	in >> line.p2;
	return in;
}


Line::~Line()
{
	// destructor
}
