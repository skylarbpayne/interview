/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Find the sum of the subarray with the maximum sum
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>

int max_subarray_sum(std::vector<int> const& a) {
	int max = 0;
	int sum = 0;
	for(int i = 0; i < a.size(); ++i) {
		sum = std::max(sum + a[i], 0);
		max = std::max(max, sum);
	}
	return max;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a list of integers" << std::endl;
		return -1;
	}
	std::vector<int> a(argc - 1);
	for(int i = 1; i < argc; ++i) {
		a[i] = atoi(argv[i]);
	}

	std::cout << max_subarray_sum(a) << std::endl;
	return 0;
}
