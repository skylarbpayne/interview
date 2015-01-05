/**
 * Author: Skylar Payne
 * Date: January 5, 2014
 * Swap two integers without using a temporary variable
 **/

#include <iostream>
#include <stdlib.h>

void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Please provide 2 integers to swap" << std::endl;
		return -1;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	swap(a, b);

	std::cout << "a: " << a << ", b: " << b << std::endl;
	return 0;
}
