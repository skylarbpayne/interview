/**
 * Author: Skylar Payne
 * Date: January 1, 2015
 * Given a sentence, reverse the words in each sentence.
 *  Ex: "Hello my name is Skylar. Nice to meet you." -> "Skylar is name my Hello. you meet to Nice."
 **/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

//Note: can easily extend to other types of punctuation with a dictionary of terminating punctuation.
std::string reverse_words(std::string const& sentences) {
	std::stack<std::string> words;
	std::stringstream reverse;
	
	int start = 0;
	for(int i = 0; i < sentences.size(); ++i) {
		if(sentences[i] == ' ') {
			words.push(sentences.substr(start, i - start));
			start = i + 1;
		} 
		
		if(sentences[i] == '.') {
			words.push(sentences.substr(start, i - start));
			start = ++i + 1; //this increments i past the period and following space.
			reverse << (reverse.tellp() == 0 ? "" : " ");
			while(!words.empty()) {
				reverse << words.top() << (words.size() == 1 ? "." : " ");
				words.pop();
			}
		}
	}
	return reverse.str();
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide the string" << std::endl;
		return -1;
	}

	std::string sentences(argv[1]);

	std::cout << reverse_words(sentences) << std::endl;
	return 0;
}
