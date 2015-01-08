/**
 * Author: Skylar Payne
 * Date: January 8, 2015
 * Write an optimized a^b function for integers (mathematical integers, not necessarily the int type)
 **/

#include <iostream>
#include <assert.h>

long long exp(long long a, long long b) {
	if(b == 0) {
		return 1;
	}
	long long res = 1;
	
	while(b > 1) {
		if(b & 1) {
			res *= a;
		}
		a *= a;
		b /= 2;
	}
	return res * a;
}

int main() {
	assert(exp(3,0) == 1);
	assert(exp(3,1) == 3);
	assert(exp(3,2) == 9);
	assert(exp(3,3) == 27);
	assert(exp(3,4) == 81);
	
	std::cout << "All tests passed" << std::endl;

	return 0;
}
