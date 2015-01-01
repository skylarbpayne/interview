/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Find the length of the longest increasing subsequence
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int lis(std::vector<int> const& a) {
	std::vector<int> mem(a.size(), 1);
	int max = 1;

	for(int i = 1; i < mem.size(); ++i) {
		for(int j = 0; j < i; ++j) {
			if(a[i] > a[j]) {
				mem[i] = std::max(mem[i], mem[j] + 1);
			}
			max = std::max(max, mem[i]);
		}
	}
	return max;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a list of integers" << std::endl;
		return -1;
	}

	std::vector<int> a(argc - 1);
	for(int i = 1; i < a.size(); ++i) {
		a[i-1] = atoi(argv[i]);
	}

	std::cout << lis(a) << std::endl;
}
