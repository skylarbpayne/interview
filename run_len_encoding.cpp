/**
 * Author: Skylar Payne
 * December 24, 2014
 * Given a string, return it's run length encoding: wwwwaaadexxxxxx -> w4a3dex6
 * Provide the inverse as well.
 **/

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

std::string run_len_encoding(std::string const& str) {
	std::stringstream s;
	for(int i = 0; i < str.size();) {
		char p = str[i];
		unsigned int count = 1;
		while(str[++i] == p) {
			++count;
		}
		s << p;
		if(count == 2) {
			s << p;
		} else if(count > 2) {
			s << count;
		}
	}
	return s.str();
}

std::string inv_run_len_encoding(std::string const& str) {
	std::stringstream s;
	std::stringstream out;
	for(int i = 0; i < str.size();) {
		char p = str[i];
		s << p;
		while(++i < str.size() && '0' <= str[i] && str[i] <= '9') {
			out << str[i];
		}
		unsigned int count = 0;
		out >> count;
		out.clear();
		for(int j = 1; j < count; ++j) {
			s << p;
		}
	}
	return s.str();
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide string to run time encode" << std::endl;
		return -1;
	}
	std::string str(argv[1]);
	std::string en = run_len_encoding(str);
	std::cout << en << std::endl;
	assert(str == inv_run_len_encoding(en));
	return 0;
}
