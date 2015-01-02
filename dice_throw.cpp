/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Given n dice each with m faces numbered 1 - m, find the number of ways to roll a sum of X.
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>

int ways_to_roll_X(int n, int m, int x) {
	//If x is greater than the maximal possible value, then there are no ways.
	if(x > n * m) {
		return 0;
	}

	std::vector<std::vector<int> > mem(n, std::vector<int>(x, 0));
	
	for(int i = 0; i < x; ++i) {
		mem[0][i] = (i < m ? 1 : 0);
	}

	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < x; ++j) {
			int bound = std::min(m, j);
			for(int k = 1; k <= bound; ++k) {
				mem[i][j] += mem[i-1][j-k];
			}
		}
	}
	return mem[n-1][x-1];
}

int main(int argc, char** argv) {
	if(argc != 4) {
		std::cout << "Please provide n, m, and x." << std::endl;
		return -1;
	}

	std::cout << ways_to_roll_X(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])) << std::endl;
	return 0;
}
