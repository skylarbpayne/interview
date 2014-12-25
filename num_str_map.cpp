/**
 * Author: Skylar Payne
 * Date: December 24, 2014
 * There's a mapping of numbers to letters: 1->a, 2->b, 3->c,...,26->z.
 *  Find the number of words that can be created given a number
 *  Ex: 11 -> {"aa", "k"}
 **/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

unsigned int num_mappings(std::string const& num) {
	std::vector<unsigned int> counts(num.size() + 1);
	int i;
	//find first non-zero number
	for(i = num.size(); i >= 0 && num[i] == '0'; --i);
	if(i == 0 && num[i] == '0') {
		return 0;
	}
	counts[i--] = 1;
	for(; i >= 0; --i) {
		if(num[i] == '0') {
			continue;
		}
		counts[i] = 0;
		counts[i] += (i + 1 <= num.size() ? counts[i + 1] : 0);
		counts[i] += ((num[i] == '1' || (num[i] == '2' && num[i + 1] <= '6')) && 
			i + 2 <= num.size() ? counts[i + 2] : 0);
	}
	for(int j = 0; j < counts.size(); ++j) {
		std::cout << counts[j] << " ";
	}
	std::cout << std::endl;
	return counts[0];
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please include 1 argument: number to find number of mappings for" << std::endl;
		return -1;
	}

	std::cout << num_mappings(argv[1]) << std::endl;

	return 0;
}
