/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Find the maximum product of lengths of rope produced from a single rope
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int rope_len_prod(int length) {
	std::vector<int> mem(length);
	for(int i = 0; i < mem.size(); ++i) {
		mem[i] = i + 1;
		for(int j = 0; j < i / 2; ++j) {
			mem[i] = std::max(mem[i], mem[j] * mem[i-j-1]);
		}
	}
	return mem[length-1];
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide a length of rope" << std::endl;
		return -1;
	}

	std::cout << rope_len_prod(atoi(argv[1])) << std::endl;
	return 0;
}
