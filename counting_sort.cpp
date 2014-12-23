/**
 * Author: Skylar Payne
 * Date: December 22, 2014
 * Problem: Implement counting sort
 **/

#include <iostream>
#include <vector>
#include <time.h>

void counting_sort(std::vector<int> const& input, std::vector<int>& res, unsigned int offset, unsigned int range) {
	std::vector<int> count(range + 1);

	for(int i = 0; i < input.size(); ++i) {
		count[input[i]]++;
	}
	int accum = 0;
	for(int i = 0; i < count.size(); ++i) {
		count[i] += accum;
		accum = count[i];
	}
	for(int i = 0; i < input.size(); ++i) {
		res[--count[input[i]]] = input[i];
	}
}

int main(int argc, char** argv) {
	unsigned int size = 20;
	unsigned int range = 20;
	unsigned int offset = 1;

	if(argc > 1)
		size = atoi(argv[1]);
	if(argc > 2)
		range = atoi(argv[2]);
	if(argc > 3)
		offset = atoi(argv[3]);

	srand(time(NULL));

	std::vector<int> input(size);
	for(int i = 0; i < input.size(); ++i) {
		input[i] = rand() % range + offset;
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int> res(size);
	counting_sort(input, res, offset, range);
	for(int i = 0; i < input.size(); ++i) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
