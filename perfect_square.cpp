/**
 * Author: Skylar Payne
 * Date: December 27, 2014
 * Determine if an integer is a perfect square using only addition/subtraction mathematical operations.
 **/

#include <iostream>

bool is_perfect_square(int n) {
	int i = 1;
	while(n > 0) {
		n -= i;
		i += 2;
	}
	return n == 0;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide the potential perfect square as the only argument" << std::endl;
		return -1;
	}
	std::cout << (is_perfect_square(atoi(argv[1])) ? "true" : "false") << std::endl;
	return 0;
}
