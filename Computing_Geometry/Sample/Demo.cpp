#include "../Base/Vector.h"
#include<iostream>
using namespace std;
using namespace jmk;

int main()
{
	Vector3f v31{ 1,-1,3 }, v32{4,5,8};
	v31 = v31 + v32;
	cout << v31[0] <<" "<<v31[1]<<" "<<v31[2] << endl;
	return 0;
}
