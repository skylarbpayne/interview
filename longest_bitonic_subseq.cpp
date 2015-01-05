/**
 * Author: Skylar Payne
 * Date: January 4, 2015
 * Find the length of longest bitonic subsequence. A bitonic subsequence is a subsequence that
 *  increases then decreases
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>

int lbs(std::vector<int> const& arr) {
	std::vector<int> lis(arr.size());
	std::vector<int> lds(arr.size());
	lis[0] = 1;
	lds[arr.size() - 1] = 1;
	for(int i = 1; i < arr.size(); ++i) {
		int max_lis = 1;
		int max_lds = 1;
		int lds_i = arr.size() - i - 1;
		for(int j = 0; j < i; ++j) {
			int lds_j = arr.size() - j - 1;
			max_lis = (arr[i] > arr[j] ? std::max(max_lis, lis[j] + 1) : max_lis);
			max_lds = (arr[lds_j] < arr[lds_i] ? std::max(max_lds, lds[lds_j] + 1) : max_lds);
		}
		lis[i] = max_lis;
		lds[lds_i] = max_lds;
	}
	int max = 1;
	for(int i = 0; i < arr.size(); ++i) {
		max = std::max(max, lis[i] + lds[i] - 1);
	}
	
	return max;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a list of integers" << std::endl;
		return -1;
	}

	std::vector<int> arr(argc - 1);
	for(int i = 1; i < argc; ++i) {
		arr[i-1] = atoi(argv[i]);
	}

	std::cout << lbs(arr) << std::endl;
	return 0;
}
