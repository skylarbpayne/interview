/**
 * Author: Skylar Payne
 * December 25, 2014
 * You have k lists of sorted integers. Find the smallest range including at least one number
 *  from each of the k lists.
 **/

#include <iostream>
#include <vector>

int get_min(std::vector<int> const& a) {
	int m = a[0];
	int m_ind = 0;
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] < m) {
			m = a[i];
			m_ind = i;
		}
	}
	return m_ind;
}

int get_max(std::vector<int> const& a) {
	int m = a[0];
	int m_ind = 0;
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] > m) {
			m = a[i];
			m_ind = i;
		}
	}
	return m_ind;
}

std::pair<int, int> find_range(std::vector<std::vector<int> > const& lists) {
	std::pair<int, int> range;
	std::pair<int, int> smallest_range;
	std::vector<int> indices(lists.size());
	int min_k = 0;
	int max_k = 0;

	std::vector<int> current(lists.size());
	for(int i = 0; i < lists.size(); ++i) {
		current[i] = lists[i][0];
	}
	min_k = get_min(current);
	max_k = get_max(current);
	range.first = lists[min_k][indices[min_k]];
	range.second = lists[max_k][indices[max_k]];
	smallest_range = range;
	while(++indices[min_k] < lists[min_k].size()) {
		current[min_k] = lists[min_k][indices[min_k]];
		min_k = get_min(current);
		max_k = get_max(current);
		range.first = lists[min_k][indices[min_k]];
		range.second = lists[max_k][indices[max_k]];
		smallest_range = (range.second - range.first < smallest_range.second - smallest_range.first ? range : smallest_range);
	}
	return smallest_range;
}

int main() {
	std::vector<std::vector<int> > lists{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
	std::pair<int,int> r = find_range(lists);
	std::cout << "[" << r.first << "," << r.second << "]" << std::endl;
	return 0;
}
