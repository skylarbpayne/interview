/**
 * Author: Skylar Payne
 * Date: January 5, 2014
 * Find the median of two sorted arrays
 **/

#include <iostream>
#include <vector>

int median(std::vector<int> const& a, std::vector<int> const& b) {
	int mid = (a.size() + b.size()) / 2;
	int i = 0, j = 0;
	int res;
	for(int n = 0; n < mid; ++n) {
		if(i == a.size()) {
			res = b[j++];
		} else if(j == b.size()) {
			res = a[i++];
		} else if(a[i] < b[j]) {
			res = a[i++];
		} else {
			res = b[j++];
		}
	}
	return res;
}

int main() {
	std::vector<int> a1 = {1,12,15,26,38};
	std::vector<int> b1 = {2,13,17,30,45};

	std::vector<int> a2 = {1,12,15,26,38};
	std::vector<int> b2 = {13,17,30,45};

	std::cout << median(a1, b1) << std::endl;
	std::cout << median(a2,b2) << std::endl;
	return 0;
}
