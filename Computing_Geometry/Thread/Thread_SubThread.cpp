#include<iostream>
#include<thread>
using namespace std;

void func_2(int& x) {
	while (true) {
		try {
			std::cout << x << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		catch (...) {
			std::cout << "this is a runtime error" << std::endl;
			throw std::runtime_error("this is a runtime error");
		}
	}
}

void func_1() {
	int x = 5;
	std::thread thread_2(func_2, std::ref(x));
	//由于调用了detach() thread_2的生命周期不会随着func_1的消亡而消亡
	//所以当thread_2尝试在func_1消亡后访问x,就会抛异常
	thread_2.detach();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "thread_1 finished execution\n";
}

void run() {
	std::thread thread_1(func_1);
	thread_1.join();
}

int main() {
	run();
	return 1;
}