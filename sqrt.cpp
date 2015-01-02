/**
 * Author: Skylar Payne
 * Date: January 2, 2015
 * Develop a sqrt function without using a sqrt within err.
 **/

#include <iostream>
#include <cmath>
#include <assert.h>

const double err = 0.00001;

double my_sqrt(double x) {
	double i = x / 2;
	double len = x / 2;
	double diff = i * i - x;
	while(diff <= -err || err <= diff) {
		len /= 2;
		(diff < 0 ? i += len : i -= len);
		diff = i * i - x;
	}
	return i;
}

int main() {
	const int num_tests = 9;
	double tests[] = {4, 3, 8, 7, 9, 101, 100, 61, 35};
	for(int i = 0; i < 9; ++i) {
		assert(abs(my_sqrt(tests[i]) - sqrt(tests[i])) <= err);
	}
	std::cout << "All tests passed." << std::endl;
	return 0;
}
