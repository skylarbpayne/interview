/**
 * Author: Skylar Payne
 * Date: December 28, 2014
 * Implement a string to int conversion
 **/

#include <iostream>
#include <string>

int str_to_int(char* s) {
	int sign = 1;
	if(*s == '-') {
		sign = -1;
		++s;
	}
	int num = 0;
	while(*s) {
		if('0' <= *s && *s <= '9') {
			num = num * 10 + int(*s - '0');
			++s;
		}
		else {
			throw "Not a valid integer string!";
		}
	}
	return sign * num;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Inappropriate number of arguments. Please provide a number." << std::endl;
		return -1;
	}
	
	try {
		std::cout << str_to_int(argv[1]) << std::endl;
	} catch(char* s) {
		std::cout << s << std::endl;
	}

	return 0;
}
