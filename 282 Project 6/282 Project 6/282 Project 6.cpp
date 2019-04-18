// 282 Project 6.cpp
/////////////////////

#include "pch.h"
#include "Point.h"
#include "Line.h"
#include <iostream>

using namespace std;

bool isParallel(Line<double, double, double, double> l1, Line<double, double, double, double> l2) {
	if (l1.getSlope() == l2.getSlope()) {
		return true;
	}
	return false;
}

bool isPerpendicular(Line<double, double, double, double> l1, Line<double, double, double, double> l2) {
	// the slopes should be opposite and inverse
	// so 1/2 would be perp to -2/1; 1/2 * (-2/1) = - 1
	if (l1.getSlope() * l2.getSlope() == -1) {
		return true;
	}
	return false;
}

bool isIntersecting(Line<double, double, double, double> l1, Line<double, double, double, double> l2) {
	// the only time where two lines arent intersecting is when they're parallel
	if (isParallel(l1, l2)) {
		return false;
	}
	return true;
}

Point<double, double> getIntersection(Line<double, double, double, double> l1, Line<double, double, double, double> l2) {
	double x = 0;
	double y = 0;

	// (m1)x + b1 = (m2)x + b2
	// x(m1 - m2) = b2 - b1
	// x = (b2 - b1)/(m1 - m2)

	x = (l2.getYIntersect() - l1.getYIntersect()) / (l1.getSlope() - l2.getSlope());
	
	// y = mx + b
	y = l1.getSlope() * x + l1.getYIntersect();

	return Point<double, double> (x, y);
}

int main()
{
	Line<double, double, double, double> l1;
	cin >> l1;
	cout << endl << l1 << "\n\n";

	Line<double, double, double, double> l2;
	cin >> l2;
	cout << endl << l2 << "\n\n";

	// if the two lines are parallel
	if (isParallel(l1, l2)) {
		cout << "Line1 and Line2 are parallel." << endl;
	}
	else { // if they're not parallel, they're intersecting
		if (isPerpendicular(l1, l2)) { // if they're specifically perpendicualr
			cout << "Line1 and Line2 are perpendicular." << endl;
		}
		else if (isIntersecting(l1, l2)) { // if they're not perpendicular and not parallel
			cout << "Line1 and Line2 are intersecting." << endl; \
		}

		// get the point where the two lines interesect
		Point<double, double> intersection = getIntersection(l1, l2);

		cout << "They intersect at " << intersection << endl;
	}
}
