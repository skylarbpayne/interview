/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Find the minimum cost for a BST given a sorted array of keys and the frequency each key is accessed
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <assert.h>

int min_cost_of_bst(std::vector<int> const& keys, std::vector<int> const& freq) {
	std::vector<std::vector<int> > mem(keys.size(), std::vector<int>(keys.size(), 0));

	for(int i = 0; i < mem.size(); ++i) {
		mem[i][i] = freq[i];
	}

	for(int len = 2; len <= mem.size(); ++len) {
		for(int i = 0; i < mem.size() - len + 1; ++i) {
			int j = i + len - 1;

			int min = INT_MAX;
			int sum = 0;
			int to = std::min(j + 1, int(mem.size()));
			for(int r = i; r < to; ++r) {
				sum += freq[r];
				int v = (r == 0 ? 0 : mem[i][r-1]) + (r == freq.size() - 1 ? 0 : mem[r+1][j]);
				min = std::min(min, v);
			}
			mem[i][j] = sum + min;
		}
	}
	return mem[0][mem.size()-1];
}

int main() {
	std::vector<int> k1 = {10,12};
	std::vector<int> f1 = {34,50};

	std::vector<int> k2 = {10,12,20};
	std::vector<int> f2 = {34,8,50};
	
	assert(min_cost_of_bst(k1,f1) == 118);
	assert(min_cost_of_bst(k2,f2) == 142);

	std::cout << "All tests passed." << std::endl;

	return 0;
}
