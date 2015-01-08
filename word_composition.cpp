/**
 * Author: Skylar Payne
 * Date: January 8, 2015
 * Given a dictionary of words and a key, check whether the key is composed of an arbitrary number of
 *  words from the dictionary.
 **/

#include <iostream>
#include <string>
#include <set>
#include <vector>

bool is_composed(std::set<std::string> const& dict, std::string const& key) {
	std::vector<bool> mem(key.size());
	std::vector<int> word_splits;

	for(int i = 0; i < mem.size(); ++i) {
		mem[i] = (dict.find(key.substr(0, i)) != dict.end());
		for(int j = 0; j < word_splits.size(); ++j) {
			mem[i] = mem[i] || (mem[word_splits[j]] && 
				 dict.find(key.substr(word_splits[j] + 1, i - word_splits[j])) != dict.end()); 
		}
		if(mem[i]) {
			word_splits.push_back(i);
		}
	}
	return mem[key.size() - 1];
}

int main(int argc, char** argv) {
	if(argc < 3) {
		std::cout << "Please provide a key and a list of words to store into the dictionary" << std::endl;
		return -1;
	}

	std::string key(argv[1]);
	std::set<std::string> dict;
	for(int i = 2; i < argc; ++i) {
		dict.insert(argv[i]);
	}
	std::cout << (is_composed(dict, key) ? "true" : "false") << std::endl;
	return 0;
}
