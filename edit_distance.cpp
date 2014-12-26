/**
 * Author: Skylar Payne
 * Date: December 26, 2014
 * Calculate the edit distance between two strings
 **/

#include <iostream>
#include <vector>
#include <algorithm>

int edit_distance(std::string const& a, std::string const& b) {
	std::vector<std::vector<int> > res(a.size() + 1, std::vector<int>(b.size() + 1));
	for(int i = 0; i < res.size(); ++i) {
		res[i][0] = i;
	}
	for(int i = 0; i < res[0].size(); ++i) {
		res[0][i] = i;
	}
	for(int i = 1; i < res.size(); ++i) {
		for(int j = 1; j < res[0].size(); ++j) {
			if(a[i] == b[j]) {
				res[i][j] = res[i -1][j - 1];
			} else {
				res[i][j] = 1 + std::min(res[i -1][j], res[i][j - 1]);
			}
		}
	}
	return res[a.size()][b.size()];
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Please provide 2 strings to calculate the edit distance of." << std::endl;
		return -1;
	}

	std::string a(argv[1]);
	std::string b(argv[2]);
	std::cout << edit_distance(a, b) << std::endl;
	return 0;
}
