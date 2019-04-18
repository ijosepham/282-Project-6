#pragma once
#include "Point.h"

template <class T, class U>
class Line
{
private:
	Point <T, U> p1;
	Point <T, U> p2;

	double a;
	double b;
	double c;

	double m;
	double n;
public:
	// constructors
	Line() {
		p1 = Point <T, U> ();
		p2 = Point <T, U> ();
		solveLine();
	}
	Line(Point <T, U> newP1, Point <T, U> newP2) {
		p1 = newP1;
		p2 = newP2;
		solveLine();
	}
	Line(T x1, U y1, V x2, W y2) {
		p1 = Point <T, U> (x1, y1);
		p2 = Point <T, U> (x2, y2);
		solveLine();
	}

	// setters
	void setP1(Point <T, U> newP1) {
		p1 = newP1;
		solveLine();
	}
	void setP2(Point <T, U> newP2) {
		p2 = newP2;
		solveLine();
	}
	void setP1(T x, U y) {
		p1 = Point <T, U> (x, y);
		solveLine();
	}
	void setP2(V x, W y) {
		p2 = Point <T, U> (x, y);
		solveLine();
	}

	// getters
	Point <T, U> getP1() {
		return p1;
	}
	Point <T, U> getP2() {
		return p2;
	}
	double getSlope() {
		return m;
	}
	double getYIntersect() {
		return n;
	}
	
	//
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

	// friend cin/cout
	friend ostream& operator<<(ostream& out, const Line& line)
	{
		out << "Point A: " << line.p1 << endl;
		out << "Point B: " << line.p2 << endl;
		out << "Line: " << line.a << "x + " << line.b << "y = " << line.c << endl;
		out << "Line: " << "y = " << line.m << "x + " << line.n << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Line& line)
	{
		cout << "Point A: " << endl;
		in >> line.p1;
		cout << endl << "Point B: " << endl;
		in >> line.p2;
		line.solveLine();
		return in;
	}

	~Line() {
		// destructor
	}
};

