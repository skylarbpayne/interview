#include <iostream>
#include <unordered_map>
#include <string>

void update_count(std::unordered_map<char, int>& counts, char key, int update) {
	if(counts.find(key) == counts.end()) {
		counts[key] = 0;
	}
	counts[key] += update;
	if(counts[key] == 0) {
		counts.erase(key);
	}
}

std::string find_shortest_substring_with_entire_alphabet(std::string str, std::string alph) {
	std::unordered_map<char, int> window;
	//initialize with charaters of str up to length of alph
	for(int i = 0; i < alph.size(); ++i) {
		update_count(window, str[i], 1);		
	}

	//some temp variables to hold the substring we find!
	std::string shortest_substr = ""; // no solution
	int i = 0, j = alph.size() - 1; // current positions of the window

	//Go until we search the last substring
	while(j < str.size() || i < str.size() - alph.size() + 1) {
		//Check if we have found a new solution:
		if(window.size() == alph.size() && (j - i + 1 < shortest_substr.size() || shortest_substr == "")) {
			shortest_substr = str.substr(i, i - j + 1);
		}
		//always reduce first
		if(window[str[i]] > 1) {
			update_count(window, str[i++], -1);
		} else {
			update_count(window, str[++j], 1);
		}
	}

	return shortest_substr;
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Inappropriate number of arguments! Please provide the string and alphabet." << std::endl;
		return 1;
	}

	std::cout << find_shortest_substring_with_entire_alphabet(argv[1], argv[2]) << std::endl;
	return 0;
}
