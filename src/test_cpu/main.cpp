#include <iostream>
#include <opencv2/core.hpp>

void test_dmesg() {
	std::cout << "[enter] " << __func__ << std::endl;
	int val = 247;
	int *p = nullptr;
	*p = val;
	std::cout << "p[" << p << "]: " << *p << std::endl;
}

void test_print() {
	std::cout << "[enter] " << __func__ << std::endl;
}

int main() {
	test_print();
	test_dmesg();

	return 0;
}
