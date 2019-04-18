#pragma once
#include "Point.h"

class Line
{
private:
	Point p1;
	Point p2;

	double a;
	double b;
	double c;

	double m;
	double n;
public:
	// constructors
	Line();
	Line(Point, Point);
	Line(double, double, double, double);

	// setters
	void setP1(Point);
	void setP2(Point);
	void setP1(double, double);
	void setP2(double, double);

	// getters
	Point getP1();
	Point getP2();
	double getSlope();
	
	//
	void solveLine();

	// friend cin/cout
	friend ostream& operator<<(ostream&, const Line&);
	friend istream& operator>>(istream&, Line&);

	~Line();
};

