#include<iostream>
#include<functional>
using namespace std;

int main() {
	//һ�²���һЩ�º���ʵ��
	plus<int> plusobj;	//�ӷ�
	minus<int> minusobj;//����
	divides<int> dividesobj;//�˷�
	multiplies<int> multipliesobj;//����
	modulus<int> modulusobj;//ģȡ(����)
	negate<int> negateobj;//��(ȡ��)

 
	cout << plusobj(3, 5) << endl;
	cout << minusobj(3, 5) << endl;
	cout << dividesobj(3, 5) << endl;
	cout << multipliesobj(3, 5) << endl;
	cout << modulusobj(3, 5) << endl;
	cout << negateobj(3) << endl;

	return 0;
}