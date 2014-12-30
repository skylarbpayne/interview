/**
 * Author: Skylar Payne
 * Date: December 24, 2014
 * Check if a binary tree is a valid binary search tree
 **/

#include <iostream>
#include <time.h>
#include <assert.h>
#include <limits.h>

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node( int v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r) { }
};

Node* insert(Node* root, int v) {
	if(root == nullptr) {
		return new Node(v);
	}
	if(v <= root->value) {
		root->left = insert(root->left, v);
	} else {
		root->right = insert(root->right, v);
	}
	return root;
}

void destroy_tree(Node* root) {
	if(root == nullptr)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	delete root;
}

bool is_valid_BST(Node* root, int l = INT_MIN, int r = INT_MAX) {
	if(root == nullptr)
		return true;
	bool v = (l <= root->value) && (root->value <= r);
	return v && is_valid_BST(root->left, l, root->value) && is_valid_BST(root->right, root->value, r);
}

int main(int argc, char** argv) {
	srand(time(NULL));
	Node* root = insert(nullptr, rand() % 200);
	for(int i = 1; i < 100; ++i) {
		root = insert(root, rand() % 200);
	}
	
	assert(is_valid_BST(root) == true);
	assert(is_valid_BST(nullptr) == true);
	Node* root2 = new Node(4);
	root2->left = new Node(6);
	root2->right = new Node(5);
	assert(is_valid_BST(root2) == false);
	
	std::cout << "Tests passed" << std::endl;

	destroy_tree(root);
	destroy_tree(root2);
	return 0;
}
