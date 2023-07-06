#include<iostream>
#include<thread>
using namespace std;

void test() {
	printf("Hello from test\n");
}

void run() {
	std::thread thread1(test);
	if (thread1.joinable()) {
		printf("1 is joinable thread \n");
	}
	else {
		printf("1 is not a joinable thread\n");
	}
	
	thread1.join();

	if (thread1.joinable()) {
		printf("1 is joinable thread\n");
	}
	else {
		printf("1 is not a joinable thread\n");
	}

}

int main() {
	run();
	return 1;
}