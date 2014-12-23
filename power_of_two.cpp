/**
 * Author: Skylar Payne
 * Date: December 22, 2014
 * This program finds if an integer is a power of two
 **/

#include <iostream>
#include <stdlib.h>

bool is_power_of_two(unsigned int a) {
	return !(a & (a - 1));
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Incorrect number of arguments. Please provide a number" << std::endl;
		return -1;
	}
	std::cout << (is_power_of_two(atoi(argv[1])) ? "true" : "false") << std::endl;
	return 0;
}
