#pragma once

#include<math.h>

#define TOLERENCE 0.0000001

//点在线的哪里
enum RELATIVE_POSITION {
	LEFT,RIGHT,BEHIND,BEYOND,BETWEEN,ORIGIN,DESTINATION
};

static bool isEqualD(double x, double y) {
	return fabs(x - y) < TOLERENCE;
}

static bool _xor(bool x, bool y) {
	return x ^ y;
}