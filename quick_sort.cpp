/**
 * Author: Skylar Payne
 * Date: January 7, 2015
 * Implement quick-sort in place
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>

void qsort(std::vector<int>& a, int low = 0, int high = -1) {
	if(high == -1) {
		high = a.size() - 1;
	}

	if(high <= low) {
		return;
	}
	
	int piv = rand() % (high - low + 1) + low;
	int swap_ind = 0;
	std::swap(a[piv], a[high]); 
	for(int i = 0; i < high; ++i) {
		if(a[i] < a[high]) {
			std::swap(a[i], a[swap_ind++]);
		}
	}
	std::swap(a[high], a[swap_ind]);
	qsort(a, low, swap_ind);
	qsort(a, swap_ind+1, high);
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a list of integers to sort" << std::endl;
		return -1;
	}

	std::vector<int> a(argc - 1);
	for(int i = 1; i < argc; ++i) {
		a[i-1] = atoi(argv[i]);
	}
	
	qsort(a);
	for(int i = 1; i < a.size(); ++i) {
		assert(a[i-1] <= a[i]);
	}

	std::cout << "Sorted" << std::endl;
	return 0;
}
