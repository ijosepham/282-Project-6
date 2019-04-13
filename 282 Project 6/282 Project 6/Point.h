// Point.h
///////////

#pragma once
#include <iostream>

using namespace std;

class Point
{
private:
	long x;
	long y;
public:
	// constructors
	Point();
	Point(long, long);
	
	// setters
	void setX(long);
	void setY(long);
	
	// getters
	long getX();
	long getY();
	// friends cin/cout
	friend ostream& operator<<(ostream&, Point&);
	friend istream& operator>>(istream&, Point&);

	~Point();
};

