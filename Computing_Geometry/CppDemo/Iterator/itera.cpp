#include<iostream>
#include<functional>
using namespace std;

int main() {
	//一下产生一些仿函数实体
	plus<int> plusobj;	//加法
	minus<int> minusobj;//减法
	divides<int> dividesobj;//乘法
	multiplies<int> multipliesobj;//除法
	modulus<int> modulusobj;//模取(余数)
	negate<int> negateobj;//否定(取反)

 
	cout << plusobj(3, 5) << endl;
	cout << minusobj(3, 5) << endl;
	cout << dividesobj(3, 5) << endl;
	cout << multipliesobj(3, 5) << endl;
	cout << modulusobj(3, 5) << endl;
	cout << negateobj(3) << endl;

	return 0;
}