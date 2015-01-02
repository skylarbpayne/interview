/**
 * Author: Skylar Payne
 * Date: December 29, 2014
 * Given a BST and an integer, x, find if two integers in the BST sum to x.
 **/

#include <iostream>
#include <stack>
#include <assert.h>

class Node {
	public:
		int value;
		Node* left;
		Node* right;

		Node(int v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r) { }
};

Node* insert(Node* root, int value) {
	if(root == nullptr) {
		return new Node(value);
	}

	if(value < root->value) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}
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

bool sum_to_x(Node* root, int x) {
	std::stack<Node*> left, right;
	Node* c = root;
	while(c != nullptr) {
		left.push(c);
		c = c->left;
	}
	c = root;
	while(c != nullptr) {
		right.push(c);
		c = c->right;
	}
	while(!left.empty() && !right.empty() && left.top() != right.top()) {
		int sum = left.top()->value + right.top()->value;
		if(sum == x) {
			return true;
		}
		if(sum < x) {
			//next node of inorder traversal from left
			c = left.top()->right;
			left.pop();
			while(c != nullptr) {
				left.push(c);
				c = c->left;
			}
		} else {
			//next node of reverse inorder traversal from right
			c = right.top()->left;
			right.pop();
			while(c != nullptr) {
				right.push(c);
				c = c->right;
			}
		}
	}
	return false;
}

int main() {
	Node* root = insert(nullptr, 3);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, -2);

	assert(sum_to_x(root, 0) == true);
	assert(sum_to_x(root, 1) == true);
	assert(sum_to_x(root, 3) == true);
	assert(sum_to_x(root, 8) == true);
	assert(sum_to_x(root, 5) == true);
	assert(sum_to_x(root, -1) == true);
	assert(sum_to_x(root, -3) == false);
	assert(sum_to_x(root, 12) == false);

	std::cout << "All tests passed" << std::endl;
	return 0;
}
