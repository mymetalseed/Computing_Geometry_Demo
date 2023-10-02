#include <iostream>
#include<vector>
using namespace std;

//����operator(),plus�����һ���º���
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

	//����ʹ�÷º���,��������һ�㺯��һ��
	cout << plusobj(3, 5) << endl;
	cout << minusobj(3, 5) << endl;

	//��ʱ����º���
	cout << M_plus<int>()(43, 50) << endl;
	cout << M_minus<int>()(43, 50) << endl;

	vector<int> a;

	return 0;
}