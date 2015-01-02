/**
 * Author: Skylar Payne
 * Date: January 2, 2015
 * Find the longest palindromic substring
 **/

#include <iostream>
#include <vector>
#include <string>

std::string longest_palindrome_substr(std::string const& a) {
	if(a.size() == 0) {
		return "";
	}

	std::vector<std::vector<bool> > mem(a.size() + 1, std::vector<bool>(a.size() + 1, true));
	int start = 0, length = 1;
	for(int L = 2; L <= a.size(); ++L) {
		for(int i = 1; i <= mem.size() - L; ++i) {
			int j = i + L - 1;
			mem[i][j] = (a[i-1] == a[j-1] && mem[i+1][j-1]);
			if(mem[i][j]) {
				start = i;
				length = L;
			}
		}
	}
	return a.substr(start - 1,length);
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide a string argument" << std::endl;
		return -1;
	}

	std::string a(argv[1]);
	std::cout << longest_palindrome_substr(a) << std::endl;
	return 0;
}
