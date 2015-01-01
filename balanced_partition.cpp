/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Determine if there is a balanced partition of a given array
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>

bool balanced_partition(std::vector<int> const& a) {
	int sum = 0;
	for(int i = 0; i < a.size(); ++i) {
		sum += a[i];
	}

	if(sum % 2 == 1) {
		return false;
	}

	std::vector<std::vector<bool> > mem(a.size() + 1, std::vector<bool>(sum / 2 + 1, false));

	for(int j = 0; j < mem[0].size(); ++j) {
		for(int i = 1; i < mem.size(); ++i) {
			mem[i][j] = ((a[i-1] == j) || (mem[i-1][j]) || (j - a[i-1] >= 0 ? mem[i-1][j-a[i-1]] : false));
		}
	}
	
	return mem[a.size()][sum / 2];
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a list of integers" << std::endl;
		return -1;
	}

	std::vector<int> a(argc - 1);
	for(int i = 1; i < argc; ++i) {
		a[i-1] = atoi(argv[i]);
	}

	std::cout << (balanced_partition(a) ? "true" : "false") << std::endl;
	return 0;
}
