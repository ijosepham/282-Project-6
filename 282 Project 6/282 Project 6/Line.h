#pragma once
#include "Point.h"

class Line
{
private:
	Point a;
	Point b;
public:
	// constructors
	Line();
	Line(Point, Point);
	Line(double, double, double, double);

	// setters
	void setA(Point);
	void setB(Point);
	void setA(double, double);
	void setB(double, double);

	// getters
	Point getA();
	Point getB();

	// friend cin/cout
	friend ostream& operator<<(ostream&, const Line&);
	friend istream& operator>>(istream&, Line&);

	~Line();
};

