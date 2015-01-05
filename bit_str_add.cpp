/**
 * Author: Skylar Payne
 * Date: January 5, 2014
 * Given two strings representing bits, return their sum
 **/

#include <iostream>
#include <string>

//Note: This will ONLY work for properly formatted bit strings.
std::string add(std::string a, std::string b) {
	int length = std::max(a.size(), b.size());
	if(a.size() > b.size()) {
		b = std::string(a.size() - b.size(), '0') + b;
	} else if(b.size() > a.size()) {
		a = std::string(b.size() - a.size(), '0') + a;
	}
	std::string res(length, '0');
	int c = 0, i = length - 1;
	do {
		int bit_ai = a[i] - '0';
		int bit_bi = b[i] - '0';
		int bit_ci = (bit_ai ^ bit_bi ^ c) + '0';
		c = ((bit_ai ^ bit_bi) & c) | (bit_ai & bit_bi);
		res[i] = bit_ci;
	} while(--i >= 0);
	
	return res;
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Please provide 2 bit strings to add" << std::endl;
		return -1;
	}

	std::string a(argv[1]);
	std::string b(argv[2]);

	std::string c = add(a, b);

	std::cout << c << std::endl;
	return 0;
}
