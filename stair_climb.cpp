/**
 * Author: Skylar Payne
 * Date: December 24, 2014
 * Find the number of ways to climb n steps when you can climb up to
 * 	k steps at a time
 **/

#include <iostream>
#include <vector>

unsigned int num_ways_to_climb(unsigned int n, unsigned int k) {
	std::vector<unsigned int> counts(n + 1);
	counts[n] = 1;
	for(int i = n - 1; i >= 0; --i) {
		unsigned int accum = 0;
		for(int j = 1; j <= k && i + j <= n; ++j) {
			accum += counts[i + j];
		}
		counts[i] = accum;
	}
	return counts[0];
}

int main(int argc, char** argv) {
	if(argc < 3) {
		std::cout << "Provide 2 arguments: n and k" << std::endl;
		return -1;
	}

	unsigned int n = atoi(argv[1]);
	unsigned int k = atoi(argv[2]);
	std::cout << num_ways_to_climb(n, k) << std::endl;
	return 0;
}
