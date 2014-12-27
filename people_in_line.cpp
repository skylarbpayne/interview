/**
 * Author: Skylar Payne
 * Date: December 27, 2014
 * Given 2 arrays: one holding the heights of people in line (int) and the second
 *  telling how many people in front of that person are taller. Give the order
 *  of people in line.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void order(std::vector<int> const& height, std::vector<int> const& inFront, std::vector<int>& res) {
	//2 things can be done to improve this solution:
	// 1) use bucket/counting sort since the range of heights is small - (O(n) vs O(nlogn)).
	// 2) use balanced BST or union find to keep track of filled indices so that you
	//		can do CRUD operations in O(logn) time and have O(nlogn) solution.
	
	std::vector<std::pair<int, int> > comb(height.size());
	for(int i = 0; i < height.size(); ++i) {
		comb[i] = std::make_pair(height[i], inFront[i]);
	}
	std::sort(comb.begin(), comb.end());
	std::set<int> used_ind;
	for(int i = 0; i < comb.size(); ++i) {
		int ind = comb[i].second;
		while(used_ind.find(ind) != used_ind.end() && ind < res.size()) {
			++ind;
		}
		used_ind.insert(ind);
		res[ind] = comb[i].first;
	}
}

int main(int argc, char** argv) {
	std::vector<int> height, inFront, res;
	if(argc == 1) {
		height.resize(3);
		inFront.resize(3);
		res.resize(3);
		height[0] = 3;
		height[1] = 2;
		height[2] = 1;
		inFront[0] = 0;
		inFront[1] = 1;
		inFront[2] = 1;
	} else if(argc % 2 == 1) {
		height.resize(argc / 2);
		inFront.resize(argc / 2);
		for(int i = 1; i < argc / 2; ++i) {
			height[i] = atoi(argv[i]);
			inFront[i] = atoi(argv[i + argc / 2]);
		}
	} else {
		std::cout << "Inappropriate number of arguments" << std::endl;
		return -1;
	}
	order(height, inFront, res);
	for(int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
