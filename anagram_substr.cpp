/**
 * Author: Skylar Payne
 * Date: December 29, 2014
 * Find if a string contains any anagram of another string
 **/

#include <iostream>
#include <string>
#include <unordered_map>

void insert_to_dict(std::unordered_map<char, int>& counts, char key, int amt) {
	if(counts.find(key) == counts.end()) {
		counts[key] = amt;
	} else {
		counts[key] += amt;
	}
	if(counts[key] == 0) {
		counts.erase(key);
	}
}

//is an anagram of b in a?
bool contains_anagram(std::string const& a, std::string const& b) {
	std::unordered_map<char, int> counts;
	for(int i = 0; i < b.size(); ++i) {
		insert_to_dict(counts, b[i], 1);
	}
	
	int start = 0, end = b.size() - 1;
	for(int i = start; i <= end; ++i) {
		insert_to_dict(counts, a[i], -1);
	}

	while(end < a.size()) {
		if(counts.empty()) {
			return true;
		}
		insert_to_dict(counts, a[start++], 1);
		insert_to_dict(counts, a[++end], -1);  
	}
	return false;
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Please provide 2 strings as arguments" << std::endl;
		return -1;
	}

	std::string a(argv[1]);
	std::string b(argv[2]);
	std::cout << (contains_anagram(a, b) ? "true" : "false") << std::endl;
	return 0;
}
