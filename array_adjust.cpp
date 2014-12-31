/**
 * Author: Skylar Payne
 * Date: December 31, 2014
 * Adjust integers in an array so that all integers are within k of each other with minimum adjustments
 *  You can assume that all integers are positive and less than 100.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
const int max_int = 100;

int min_adjustments(std::vector<int> const& arr, int k) {
	std::vector<std::vector<int> > mem(arr.size(), std::vector<int>(max_int));
	int min_adj;
	
	for(int i = 0; i < max_int; ++i) {
		mem[0][i] = std::abs(arr[0] - (i + 1));
	}
	
	for(int i = 1; i < arr.size(); ++i) {
		min_adj = INT_MAX;
		for(int j = 0; j < max_int; ++j) {
			int from = std::max(0, j - k), to = std::min(max_int - 1, j + k);
			int min = INT_MAX;
			for(int w = from; w <= to; ++w) {
				min = std::min(min, std::abs(arr[i] - (j + 1)) + mem[i-1][w]);
			}
			mem[i][j] = min;
			min_adj = std::min(min_adj, min);
		}
	}
	return min_adj;
}

int main(int argc, char** argv) {
	if(argc < 3) {
		std::cout << "Please provide k and a list of integers" << std::endl;
		return -1;
	}

	int k = atoi(argv[1]);
	std::vector<int> arr(argc - 2);
	for(int i = 2; i < argc; ++i) {
		arr[i-2] = atoi(argv[i]);
	}
	std::cout << min_adjustments(arr, k) << std::endl;
	return 0;
}
