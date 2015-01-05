/**
 * Author: Skylar Payne
 * Date: January 5, 2014
 * Turn off the rightmost set bit in an integer
 **/

#include <iostream>
#include <stdlib.h>

int turn_off_right_set_bit(int x) {
	return x & (x - 1);
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide an integer" << std::endl;
		return -1;
	}

	int x = atoi(argv[1]);
	std::cout << turn_off_right_set_bit(x) << std::endl;
	return 0;
}
