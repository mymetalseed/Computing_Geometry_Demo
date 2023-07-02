#include "../Core/Base/Vector.h"
#include "../Core/GeoUtils.cpp"
#include<iostream>
using namespace std;
using namespace jmk;

int main()
{
	Vector3f v31{ 1,-1,3 }, v32{4,5,8};
	v31 = v31 + v32;

	Point2d pt1{ 0,0 }, pt2{ 1,1 }, pt3{0.5,0.5};

	cout << orientation2d(pt1, pt2, pt3)<<endl;

	cout << v31[0] <<" "<<v31[1]<<" "<<v31[2] << endl;
	return 0;
}
