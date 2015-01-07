/**
 * Author: Skylar Payne
 * Date: January 5, 2015
 * Find the number of bit strings of length n without consecutive set bits
 **/

#include <iostream>
#include <assert.h>

int num_strings_wo_consecutive_set_bits(int n) {
	if(n <= 0) {
		return 0;
	} else if(n == 1) {
		return 2;
	}

	int f2 = 1;
	int f1 = 2;
	int f;
	for(int i = 2; i <= n; ++i) {
		f = f1 + f2;
		f2 = f1;
		f1 = f;
	}
	
	return f;
}

int main() {
	assert(num_strings_wo_consecutive_set_bits(0) == 0);
	assert(num_strings_wo_consecutive_set_bits(1) == 2);
	assert(num_strings_wo_consecutive_set_bits(2) == 3);
	assert(num_strings_wo_consecutive_set_bits(3) == 5);
	assert(num_strings_wo_consecutive_set_bits(4) == 8);

	std::cout << "All tests passed" << std::endl;
	return 0;
}
