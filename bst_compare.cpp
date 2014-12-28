/**
 * Author: Skylar Payne
 * Date: December 28, 2014
 * Compare two arrays and determine if they would produce the same BST without making the BST
 **/

#include <iostream>
#include <vector>
#include <assert.h>

bool makes_same_bst(std::vector<int> const& a, std::vector<int> const& b) {
	if(a.size() != b.size()) {
		return false;
	} else if(a.size() == 0) {
		return true;
	} else if(a[0] != b[0]) {
		return false;
	}	
	std::vector<int> al, ag, bl, bg;
	for(int i = 1; i < a.size(); ++i) {
		a[i] < a[0] ? al.push_back(a[i]) : ag.push_back(a[i]);
	}
	for(int i = 1; i < b.size(); ++i) {
		b[i] < b[0] ? bl.push_back(b[i]) : bg.push_back(b[i]);
	}
	return makes_same_bst(al, bl) && makes_same_bst(ag, bg);
}

int main() {
	std::vector<int> a1 = {8,14,11,9,13,20,16,22};
	std::vector<int> b1 = {8,14,20,22,16,11,13,9};

	std::vector<int> a2 = {2,3,1};
	std::vector<int> b2 = {2,1,3};

	std::vector<int> a3 = {2,4,3,1};
	std::vector<int> b3 = {2,3,4,1};

	assert(makes_same_bst(a1,b1) == true);
	assert(makes_same_bst(a2,b2) == true);
	assert(makes_same_bst(a3,b3) == false);

	std::cout << "All tests passed." << std::endl;
	return 0;
}
