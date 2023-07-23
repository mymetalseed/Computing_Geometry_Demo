#include<iostream>
#include<thread>
using namespace std;

void func_1(int x, int y) {
	printf("X + Y = %d\n", x + y);
}

void func_2(int& x) {
	while (true) {
		printf("Thread 1 value of X-%d\n", x);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void run() {
	int p = 9;
	int q = 8;
	//���̴߳��ݲ���
	std::thread thread_1(func_1, p, q);
	thread_1.join();

	int x = 9;
	printf("Main thread value of X - %d\n", x);
	std::thread thread_2(func_2, std::ref(x));
	//����һ���߳��Ѿ���ʼִ����,
	//��һ������sleep��,5s�Ժ����ִ�������x=15,ֱ��thread_2.join()
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	x = 15;
	printf("Main thread value of X - %d\n", x);
	thread_2.join();
}

int main() {
	run();
	return 1;
}