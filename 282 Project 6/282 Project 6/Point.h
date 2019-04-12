// Point.h
///////////

#pragma once
#include <iostream>

using namespace std;

template < class T >
class Point
{
private:
	T x;
	T y;
public:
	// constructors
	Point();
	Point(T, T);

	// setters
	void setX(T);
	void setY(T);
	
	// getters
	T getX();
	T getY();

	// friends cin/cout
	friend ostream& operator<<(ostream&, Point&);
	friend istream& operator>>(istream&, Point&);

	~Point();
};

