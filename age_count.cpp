/**
 * Author: Skylar Payne
 * Date: January 6, 2015
 * Print out the number of people with each age given a sorted array of ages
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>

void print_age_counts(std::vector<int> const& ages) {
	if(ages.empty()) {
		return;
	}
	int age = ages[0];
	int begin_ind = 0;
	int end_ind = ages.size();
	int count = 0;
	while(count < ages.size()) {
		//search for age, print out
		int mid = (begin_ind + end_ind) / 2;
		if(ages[mid] == age && (mid + 1 == ages.size() || ages[mid+1] != age)) {
			//This is where the boundary is.
			std::cout << age << ": " << mid - count + 1 << std::endl;
			count = mid + 1;
			begin_ind = mid + 1;
			age = (mid + 1 < ages.size() ? ages[mid+1] : 0);
			end_ind = ages.size();
		} else if(ages[mid] <= age) {
			begin_ind = mid + 1;
		} else {
			end_ind = mid;
		}
	}
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a sorted list of ages" << std::endl;
		return -1;
	}

	std::vector<int> ages(argc - 1);
	for(int i = 1; i < argc; ++i) {
		ages[i-1] = atoi(argv[i]);
	}

	print_age_counts(ages);
	return 0;
}
