/**
 * Author: Skylar Payne
 * Date: January 6, 2015
 * Convert a BST to a doubly linked list with constant auxiliary memory
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r) { }
};

Node* insert(int v, Node* root = nullptr) {
	if(root == nullptr) {
		return new Node(v);
	}

	if(v <= root->value) {
		root->left = insert(v, root->left);
	} else {
		root->right = insert(v, root->right);
	}

	return root;
}

void destroy(Node* root = nullptr) {
	if(root == nullptr) {
		return;
	}

	destroy(root->right);
	delete root;
}

Node* convert_to_list(Node* root) {
	if(root == nullptr) {
		return nullptr;
	}
	Node* cur = root;

	Node* begin = nullptr;
	Node* last_examined = nullptr;
	
	while(cur != nullptr) {
		if(cur->left != nullptr) {
			Node* n = nullptr;
			for(n = cur->left; n->right != nullptr; n = n->right);
			n->right = cur;
			Node* tmp = cur;
			cur = cur->left;
			tmp->left = nullptr;	
		} else {
			if(last_examined == nullptr) {
				begin = cur;
			} else {
				cur->left = last_examined;
				cur->left->right = cur;
			}
			last_examined = cur;
			cur = cur->right;
		}
	}
	return begin;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please provide a list of numbers to insert into a BST" << std::endl;
		return -1;
	}

	std::vector<int> arr(argc - 1);
	for(int i = 1; i < argc; ++i) {
		arr[i-1] = atoi(argv[i]);
	}

	Node* root = nullptr;
	for(int i = 0; i < arr.size(); ++i) {
		root = insert(arr[i], root);
	}
	sort(arr.begin(), arr.end());
	Node* list = convert_to_list(root);
	
	int i = 0;
	Node* prev = nullptr;
	for(Node* l = list; l != nullptr; l = l->right) {
		assert(i < arr.size());
		assert(l->value == arr[i]);
		assert(l->left == prev);
		std::cout << l->value << " ";
		++i;
		prev = l;
	}
	std::cout << std::endl;
	destroy(list);
	return 0;
}
