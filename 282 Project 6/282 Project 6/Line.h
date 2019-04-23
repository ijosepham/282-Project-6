#pragma once
#include "Point.h"

template <class T, class U, class V, class W>
class Line
{
private:
	// represents two potints on the line
	Point <T, U> p1;
	Point <V, W> p2;

	// variables for standard form. Ax + By = C
	double a;
	double b;
	double c;

	// variables for point-slope form. y = mx + b
	double m;
	double n;
public:
	// description: default constructor
	Line() {
		p1 = Point <T, U> ();
		p2 = Point <V, W> ();
		solveLine();
	}

	// description: overloaded constructor that takes in two points
	// preconditions: newP1, newP2 - points to make a line from
	Line(Point <T, U> newP1, Point <V, W> newP2) {
		p1 = newP1;
		p2 = newP2;
		solveLine();
	}

	// description: overloaded constructor with 4 parameters for 2 x's and 2 y's
	// preconditions: x1, y1 - x and y of the first point
	//				  x2, y2 - x and y for the second point
	Line(T x1, U y1, V x2, W y2) {
		p1 = Point <T, U> (x1, y1);
		p2 = Point <V, W> (x2, y2);
		solveLine();
	}

	// description: sets the first point of the line
	// preconditions: newP1 - first point
	void setP1(Point <T, U> newP1) {
		p1 = newP1;
		solveLine();
	}

	// description: sets the second ponit of the line
	// preconditions: newP2- second point
	void setP2(Point <V, W> newP2) {
		p2 = newP2;
		solveLine();
	}

	// description: sets the first ponit of the line
	// preconditions: x, y - x and y of the first point 
	void setP1(T x, U y) {
		p1 = Point <T, U> (x, y);
		solveLine();
	}

	// description: sets the second ponit of the line
	// preconditions: x, y - x and y of the second point 
	void setP2(V x, W y) {
		p2 = Point <V, W> (x, y);
		solveLine();
	}

	// description: sets the slope of the line
	// preconditions: slope - slope of the line
	void setSlope(double slope) {
		m = slope;
	}

	// description: sets the y-intercept of the line
	// preconditions: yIntercept - y-int of the line
	void setYIntersect(double yIntercept) {
		n = yIntercept;
	}

	// description: gets the first point of the line
	// postcondition: p1 - the first point
	Point <T, U> getP1() {
		return p1;
	}
	
	// description: gets the second point of the line
	// postcondition: p2 - the second point
	Point <V, W> getP2() {
		return p2;
	}

	// description: gets the slope of the line
	// postcondition: m - slope
	double getSlope() {
		return m;
	}

	// description: gets the y-int of the line
	// postcondition: n - y-int
	double getYIntersect() {
		return n;
	}
	
	// description: solves the line and assigns all the values to the attributes
	void solveLine() {
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

	// desrcription: prints out the points of the line, and 
	//				 standard form and point-slope form of the line
	// preconditions: out - ostream to ouptut
	//				  line - line to print out
	// postcondition: out - the thing to print out
	friend ostream& operator<<(ostream& out, const Line& line)
	{
		out << "Point A: " << line.p1 << endl;
		out << "Point B: " << line.p2 << endl;
		out << "Line: " << line.a << "x + " << line.b << "y = " << line.c << endl;
		out << "Line: " << "y = " << line.m << "x + " << line.n << endl;
		return out;
	}

	// desrcription: takes in arguments to assign to the line
	// preconditions: in - istream to take in input
	//				  line - line to change 
	// postcondition: in - istream
	friend istream& operator>>(istream& in, Line& line)
	{
		cout << "Point A: " << endl;
		in >> line.p1;
		cout << endl << "Point B: " << endl;
		in >> line.p2;
		line.solveLine();
		return in;
	}

	// description: destructor
	~Line() {
		// destructor
	}
};
