#include <iostream>
#include<vector>
using namespace std;

//重载operator(),plus变成了一个仿函数
template <class T>
struct M_plus {
	T operator()(const T& x, const T& y) const { return x + y; }
};

template<class T>
struct M_minus {
	T operator()(const T& x, const T& y) const { return x - y; }
};

int main() {
	M_plus<int> plusobj;
	M_minus<int> minusobj;

	//以下使用仿函数,就类似于一般函数一样
	cout << plusobj(3, 5) << endl;
	cout << minusobj(3, 5) << endl;

	//临时对象仿函数
	cout << M_plus<int>()(43, 50) << endl;
	cout << M_minus<int>()(43, 50) << endl;

	vector<int> a;

	return 0;
}