/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Find the maxes of all (contiguous) subarrays of size k
 **/

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

//Note: If a better PQ implementation is used (where you can arbitrarily delete),
//	you can reduce runtime complexity from O(n k logk) to O(n logk)
void get_window_maxes(std::vector<int> const& arr, const int k, std::vector<int>& res) {
	if(arr.size() < k) {
		return;
	}

	std::priority_queue<int> pq;
	int i = 0;
	while(i + k <= arr.size()) {
		for(int j = i; j < i + k; ++j) {
			pq.push(arr[j]);
		}
		res.push_back(pq.top());
		++i;
		while(!pq.empty()) {
			pq.pop();
		}
	}
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
	std::vector<int> res;
	get_window_maxes(arr, k, res);
	for(int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
