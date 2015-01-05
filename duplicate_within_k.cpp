/**
 * Author: Skylar Payne
 * Date: January 5, 2014
 * Check if an array has any duplicate elements within a distance of k
 **/

#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

bool duplicates_within_k(std::vector<int> const& arr, int k) {
	std::set<int> window;
	for(int i = 0; i < arr.size(); ++i) {
		if(window.find(arr[i]) != window.end()) {
			return true;
		}
		window.insert(arr[i]);
		if(i >= k) {
			window.erase(arr[i-k]);
		}
	}
	return false;
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
	std::cout << (duplicates_within_k(arr, k) ? "True" : "False") << std::endl;
	return 0;
}
