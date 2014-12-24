/**
 * Author: Skylar Payne
 * Date: December 24, 2014
 * Find the length of a circular linked list
 **/

#include <iostream>
#include <time.h>
#include <assert.h>

class Node {
public:
	int value;
	Node* next;

	Node(int v, Node* n = nullptr) : value(v), next(n) { }
};

unsigned int length(Node* node) {
	if(node == nullptr)
		return 0;
	unsigned int len = 1;
	Node* n = node->next;
	while(n != node) {
		n = n->next;
		++len;
	}
	return len;
}

Node* insert_node(Node* s, int v) {
	if(s == nullptr) {
		s = new Node(v);
		s->next = s;
		return s;
	}

	s->next = new Node(v, s->next);
	return s;
}

void destroy_list(Node* s) {
	if(s == nullptr)
		return;
	Node* n = s->next;
	while(n != s) {
		Node* t = n;
		n = n->next;
		delete t;
	}
	delete s;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	unsigned int len = rand() % 100;
	Node* l = nullptr;
	for(int i = 0; i < len; ++i) {
		l = insert_node(l, 0);
	}
	assert(len == length(l));
	std::cout << "Test passed" << std::endl;
	destroy_list(l);
	return 0;
}
