#pragma once

#include "Primitive/Point.h"

namespace jmk {
	double areaTriangle2d(const Point2d& a, const Point2d& b, const Point2d& c);
	//点与直线的位置关系
	int orientation2d(const Point2d& a, const Point2d& b, const Point2d& c);

	// Predicate to determine whether the [Point c] is left to the segment [a b]
	bool left(const Point2d& a, const Point2d& b, const Point2d& c);
	
	// Predicate to determine whether the[Point c] is left to the segment[a b]
	bool leftOrBeyond(const Point2d& a, const Point2d& b, const Point2d& c);
}