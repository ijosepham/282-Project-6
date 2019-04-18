#include "pch.h"
#include "Line.h"
/**

Line::Line()
{
	p1 = Point();
	p2 = Point();
	solveLine();
}

Line::Line(Point newP1, Point newP2)
{
	p1 = newP1;
	p2 = newP2;
	solveLine();
}

Line::Line(double x1, double y1, double x2, double y2) 
{
	p1 = Point(x1, y1);
	p2 = Point(x2, y2);
	solveLine();
}

// setters
void Line::setP1(Point newP1)
{
	p1 = newP1;
	solveLine();
}

void Line::setP2(Point newP2)
{
	p2 = newP2;
	solveLine();
}

void Line::setP1(double x, double y)
{
	p1 = Point(x, y);
	solveLine();
}

void Line::setP2(double x, double y)
{
	p2 = Point(x, y);
	solveLine();
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

double Line::getSlope() {
	return m;
}

double Line::getYIntersect() {
	return n;
}

// basically the consturctor for the line
void Line::solveLine() {
	// ax + by = c
	// a(x1) + b(y1) = c = a(x2) + b(y2)
	// a(x1 - x2) = b(y2 - y1)
	// a = (y2 - y1); b = (x1 - x2);
	a = (p2.getY() - p1.getY());
	b = (p1.getX() - p2.getX());

	// if a is negative, flip them so a is positive; b can be either +/-
	if (a < 0) {
		a = -a;
		b = -b;
	}
	c = a * p1.getX() + b * p1.getY(); // ax + by = c

	// y = mx + n;
	// m = rise / run  = (y2 - y1) / (x2 - x1)
	m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	// n = y - mx
	n = p1.getY() - m * p1.getX();
}

// friend cin/cout
ostream& operator<<(ostream& out, const Line& line)
{	
	out << "Point A: " << line.p1 << endl;
	out << "Point B: " << line.p2 << endl;
	out << "Line: " << line.a << "x + " << line.b << "y = " << line.c << endl;
	out << "Line: " << "y = " << line.m << "x + " << line.n << endl;
	return out;
}

istream& operator>>(istream& in, Line& line)
{
	cout << "Point A: " << endl;
	in >> line.p1;
	cout << endl << "Point B: " << endl;
	in >> line.p2;
	line.solveLine();
	return in;
}


Line::~Line()
{
	// destructor
}
*/