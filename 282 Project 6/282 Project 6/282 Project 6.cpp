// 282 Project 6.cpp
/////////////////////

#include "pch.h"
#include "Point.h"
#include "Line.h"
#include <iostream>

using namespace std;

bool isParallel(Line l1, Line l2) {
	if (l1.getSlope() == l2.getSlope()) {
		return true;
	}
	return false;
}

bool isPerpendicular(Line l1, Line l2) {
	// the slopes should be opposite and inverse
	// so 1/2 would be perp to -2/1; 1/2 * (-2/1) = - 1
	if (l1.getSlope() * l2.getSlope() == -1) {
		return true;
	}
	return false;
}

bool isIntersecting(Line l1, Line l2) {

	return true;
}

Point getIntersection(Line l1, Line l2) {
	
}

int main()
{
	Line line;
	cin >> line;
	cout << line;
}
