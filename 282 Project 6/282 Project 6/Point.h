// Point.h
///////////

#pragma once
#include <iostream>

using namespace std;

class Point
{
private:
	double x;
	double y;
public:
	// constructors
	Point();
	Point(double, double);
	
	// setters
	void setX(double);
	void setY(double);
	
	// getters
	double getX();
	double getY();

	// friends cin/cout
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);

	~Point();
};

