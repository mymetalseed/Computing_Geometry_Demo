#pragma once
#include <iostream>
#include <thread>
#include "ThreadDemo/2_launch_a_thread.h"

void foo() {
	printf("Hello from foo - %d \n",std::this_thread::get_id());
}

void run() {
	std::thread thread1(foo);


	callable_class obj;
	std::thread thread2(obj);

	std::thread thread3([] {
		printf("Hello from lambda %d \n", std::this_thread::get_id());
		});

	thread1.join();
	thread2.join();
	thread3.join();

	printf("Hello from main - %d \n", std::this_thread::get_id());
}

int main() {
	run();


	return 1;
}