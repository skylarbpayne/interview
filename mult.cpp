/**
 * Author: Skylar Payne
 * Date: December 24, 2014
 * Multiplying large numbers
 **/

#include <iostream>
#include <vector>
#include <time.h>

void mult(std::vector<char> const& a, std::vector<char> const& b, std::vector<char>& res) {
	res.resize(a.size() + b.size() + 1);
	for(int i = 0; i < res.size(); ++i) {
		res[i] = 0;
	}
	
	for(int i = 0; i < b.size(); ++i) {
		char c = 0;
		for(int j = 0; j < a.size(); ++j) {	
			char tmp = b[i] * a[j] + c;
			res[i + j] += tmp % 10;
			c = tmp / 10;
		}
	}
}

int main(int argc, char** argv) {
	std::vector<char> a(20);
	std::vector<char> b(20);
	std::vector<char> res;
	
	srand(time(NULL));

	for(int i = 0; i < 20; ++i) {
		a[i] = rand() % 10;
		b[i] = rand() % 10;
	}

	mult(a, b, res);

	for(int i = a.size() - 1; i >= 0; --i) {
		std::cout << int(a[i]);
	}
	std::cout << std::endl;
	for(int i = b.size() - 1; i >= 0; --i) {
		std::cout << int(b[i]);
	}
	std::cout << std::endl;
	for(int i = res.size() - 1; i >= 0; --i) {
		std::cout << int(res[i]);
	}
	std::cout << std::endl;

	return 0;
}
