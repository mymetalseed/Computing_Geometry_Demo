#pragma once

#include<math.h>

#define TOLERENCE 0.0000001

static bool isEqualD(double x, double y) {
	return fabs(x - y) < TOLERENCE;
}