/**
 * Author: Skylar Payne
 * Date: January 7, 2015
 * Make a sorted list of integers from a square matrix that is diagonally sorted
 **/

#include <iostream>
#include <vector>
#include <assert.h>

void get_sorted_array_from_diagonal_matrix(std::vector<std::vector<int> > const& m, std::vector<int> res) {
	if(m.empty()) {
		return;
	}
	
	res.resize(m.size() * m[0].size());
	std::pair<int,int> diag_start(0, 0);
	int ind = 0;
	while(ind < res.size()) {
		int i = diag_start.first;
		int j = diag_start.second;
		while(0 <= i && i < m.size() && 0 <= j && j < m[0].size()) {
			res[ind++] = m[i++][j--];
		}
		diag_start.second == m[0].size() - 1 ? ++diag_start.first : ++diag_start.second;
	}
}

int main() {
	std::vector<std::vector<int> > m1 = {{1,2,4},{3,5,7},{6,8,9}};
	std::vector<int> res1;
	get_sorted_array_from_diagonal_matrix(m1, res1);
	
	std::vector<std::vector<int> > m2 = {{1,2,4,7},{3,5,8,10},{6,9,11,12}};
	std::vector<int> res2;
	get_sorted_array_from_diagonal_matrix(m2, res2);

	for(int i = 1; i < res1.size(); ++i) {
		assert(res1[i-1] <= res1[i]);
	}
	for(int i = 1; i < res2.size(); ++i) {
		assert(res2[i-1] <= res2[i]);
	}

	std::cout << "All tests passed" << std::endl;
	return 0;
}
