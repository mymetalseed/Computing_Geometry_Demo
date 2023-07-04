#pragma once

class callable_class {
public:
	void operator()() {
		printf("Hello from class with function call operator - %d \n", std::this_thread::get_id());
	}
};