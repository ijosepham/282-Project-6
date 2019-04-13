#include "pch.h"
#include "Line.h"


Line::Line()
{
	a = Point();
	b = Point();
}

Line::Line(Point newA, Point newB)
{
	a = newA;
	b = newB;
}

Line::Line(double x1, double y1, double x2, double y2) 
{
	a.setX(x1);
	a.setY(y1);
	b.setX(x2);
	b.setY(y2);
}

// setters
void Line::setA(Point newA)
{
	a = newA;
}

void Line::setB(Point newB)
{
	b = newB;
}

void Line::setA(double x, double y)
{
	a.setX(x);
	a.setY(y);
}

void Line::setB(double x, double y)
{
	b.setX(x);
	b.setY(y);
}


// getters
Point Line::getA()
{
	return a;
}

Point Line::getB()
{
	return b;
}


// friend cin/cout
ostream& operator<<(ostream& out, const Line& line)
{
	return out;
}

istream& operator>>(istream& in, Line& line)
{
	cout << "Point A: " << endl;
	in >> line.a;
	cout << endl << "Point B: " << endl;
	in >> line.b;
	return in;
}


Line::~Line()
{
	// destructor
}
