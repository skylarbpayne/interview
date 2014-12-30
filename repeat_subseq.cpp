/**
 * Author: Skylar Payne
 * Date: December 29, 2014
 * Determine if there is a repeating subsequence in a given string
 **/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

bool repeat_subseq(std::string const& a) {
	std::vector<std::vector<int> > mem(a.size() + 1, std::vector<int>(a.size() + 1));
	for(int i = 0; i <= a.size(); ++i) {
		mem[0][i] = mem[i][0] = 0;
	}

	for(int i = 1; i <= a.size(); ++i) {
		for(int j = 1; j <= a.size(); ++j) {
			if(i != j && a[i-1] == a[j-1]) {
				mem[i][j] = std::max({1 + mem[i - 1][j - 1], mem[i-1][j], mem[i][j-1]});
			} else {
				mem[i][j] = std::max(mem[i-1][j], mem[i][j-1]);
			}
		}
	}
	return mem[a.size()][a.size()] > 1;
}

int main() {
	assert(repeat_subseq("aabb") == true);
	assert(repeat_subseq("abba") == false);
	assert(repeat_subseq("abcab") == true);
	assert(repeat_subseq("acbdaghfb") == true);
	assert(repeat_subseq("aebcd") == false);
	std::cout << "All tests passed." << std::endl;
	return 0;
}
