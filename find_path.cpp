/**
 * Author: Skylar Payne
 * Date: January 8, 2015
 * Given an absolute path and a relative path, find the path resulting from applying the relative path to the
 *  absolute path.
 **/

#include <iostream>
#include <string>
#include <stack>

//Note: These assume properly formatted paths. E.g. a '/' character prepends every directory
std::string find_path(std::string const& abs, std::string const& rel) {
	std::string a = abs + "/";
	std::string r = rel + "/";
	std::stack<std::string> current;
	int last = 1;
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] == '/') {
			current.push(a.substr(last, i - last));
			last = i + 1;
		}
	}
	last = (r[0] == '/' ? 1 : 0);
	for(int i = last; i < r.size(); ++i) {
		if(r[i] == '/') {
			std::string s = r.substr(last, i - last);
			s == ".." ? current.pop() : current.push(s);
			last = i + 1;
		}
	}

	std::string path;
	while(!current.empty()) {
		std::string s = current.top();
		current.pop();
		path = "/" + s + path;
	}
	return path;
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Please provide an absolute and relative path" << std::endl;
		return -1;
	}

	std::string abs(argv[1]);
	std::string rel(argv[2]);

	std::cout << find_path(abs, rel) << std::endl;
	return 0;
}
