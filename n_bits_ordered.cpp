/**
 * Author: Skylar Payne
 * Date: December 31, 2014
 * Print out the numbers from 0 - 2^(n) - 1 in an order such that consecutive numbers differ by a single bit
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>

void get_ordered_numbers(int n, std::vector<int>& res) {
	res.resize(1 << n);
	for(int i = 0; i < res.size(); ++i) {
		res[i] = (i >> 1) ^ i;
	}
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide n" << std::endl;
		return -1;
	}

	std::vector<int> res;
	get_ordered_numbers(atoi(argv[1]), res);
	for(int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
