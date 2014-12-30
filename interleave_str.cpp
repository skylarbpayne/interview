/**
 * Author: Skylar Payne
 * Date: December 30, 2014
 * Determine if a given string is an interleaving of two other strings.
 **/

#include <iostream>
#include <string>
#include <vector>

bool interleaving(std::string const& a, std::string const& b, std::string const& c) {
	if(c.size() != a.size() + b.size()) {
		return false;
	}
	std::vector<std::vector<bool> > mem(a.size() + 1, std::vector<bool>(b.size() + 1));
	
	mem[0][0] = true;
	for(int i = 1; i < mem.size(); ++i) {
		mem[i][0] = (a[i-1] == c[i-1]);
	}
	for(int i = 1; i < mem[0].size(); ++i) {
		mem[0][i] = (b[i-1] == c[i-1]);
	}
	for(int i = 1; i < mem.size(); ++i) {
		for(int j = 1; j < mem[0].size(); ++j) {
			mem[i][j] = ((a[i-1] == c[i+j-1] && mem[i-1][j]) || (b[j-1] == c[i+j-1] && mem[i][j-1]));
		}
	}
	return mem[a.size()][b.size()];
}

int main(int argc, char** argv) {
	if(argc != 4) {
		std::cout << "Please provide 3 strings: The interleaving strings followed by the supposed result" << std::endl;
		return -1;
	}

	std::string a(argv[1]);
	std::string b(argv[2]);
	std::string c(argv[3]);
	std::cout << (interleaving(a, b, c) ? "true" : "false") << std::endl;
	return 0;
}
