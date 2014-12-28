/**
 * Author: Skylar Payne
 * Date: December 28, 2014
 * Given a sorted array and a number x, find if two numbers in the array sum to x
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

bool sum_to_x(std::vector<int> const& arr, int x) {
	if(arr.size() < 2) {
		return false;
	}
	int i = 0, j = arr.size() - 1;
	while (i < j) {
		int sum = arr[i] + arr[j];
		if(sum == x) {
			return true;
		}
		sum < x ? ++i : --j;
	}
	return false;
}

int main() {
	srand(time(NULL));
	std::vector<int> arr(50 + rand() % 200);
	for(int i = 0; i < arr.size(); ++i) {
		arr[i] = rand() % 1000;
	}
	std::sort(arr.begin(), arr.end());
	int x = rand() % 1000;
	std::cout << x << std::endl;
	for(int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << (sum_to_x(arr, x) ? "true" : "false") << std::endl;
	return 0;
}
