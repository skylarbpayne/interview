/**
 * Author: Skylar Payne
 * Date: December 31
 * Find the number of nodes in a BST that have values between two integers.
 **/

#include <iostream>
#include <limits.h>
#include <assert.h>

class Node {
public:	
	int value;
	int size;
	Node* left;
	Node* right;
	Node(int v, Node* l = nullptr, Node* r = nullptr) : value(v), size(1), left(l), right(r) { }
};

Node* insert(int value, Node* root = nullptr) {
	if(root == nullptr) {
		return new Node(value);
	}
	if(value < root->value) {
		root->left = insert(value, root->left);
	} else {
		root->right = insert(value, root->right);
	}
	++root->size;
	return root;
}

void destroy(Node* root) {
	if(root == nullptr) {
		return;
	}

	destroy(root->left);
	destroy(root->right);
	delete root;
}

int num_between(Node* root, int rmin, int rmax, int min = INT_MIN, int max = INT_MAX) {
	if(root == nullptr) {
		return 0;
	} else if(rmax < min || max < rmin) {
		return 0;
	} else if(rmin <= min && max <= rmax) {
		return root->size;
	}

	return ((rmin <= root->value && root->value <= rmax) ? 1 : 0) +
		num_between(root->left, rmin, rmax, min, root->value) +
		num_between(root->right, rmin, rmax, root->value, max);
}

int main() {
	Node* root = insert(90);
	root = insert(70, root);
	root = insert(110, root);
	
	assert(num_between(root, 70, 110) == 3);
	assert(num_between(root, 90, 110) == 2);
	assert(num_between(root, 90, 90) == 1);
	assert(num_between(root, 65, 75) == 1);
	assert(num_between(root, 70, 90) == 2);
	assert(num_between(root, 120, 120) == 0);
	assert(num_between(root, 60, 60) == 0);
	
	std::cout << "All tests passed." << std::endl;

	destroy(root);
	return 0;
}
