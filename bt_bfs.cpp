/**
 * Author: Skylar Payne
 * Date: January 6, 2015
 * Print out each level of a binary tree on its own line.
 **/

#include <iostream>
#include <queue>
#include <stdlib.h>

class Node {
public:	
	char value;
	Node* left;
	Node* right;
	int height = 0;
	Node(char v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r) { }
};

void print_tree(Node* root) {
	std::queue<Node*> q;
	q.push(root);
	int height = 0;
	while(!q.empty()) {
		Node* c = q.front();
		q.pop();
		if(c->height > height) {
			std::cout << std::endl;
			height = c->height;
		}
		std::cout << c->value << " ";
		if(c->left != nullptr) {
			c->left->height = c->height + 1;
			q.push(c->left);
		}
		if(c->right != nullptr) {
			c->right->height = c->height + 1;
			q.push(c->right);
		}
	}
	std::cout << std::endl;
}

void destroy(Node* root) {
	if(root == nullptr) {
		return;
	}

	destroy(root->left);
	destroy(root->right);
	delete root;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		std::cout << "Please input a list of characters" << std::endl;
		return -1;
	}
	int i = 1;
	std::queue<Node*> q;
	Node* root = new Node(argv[i++][0]);
	q.push(root);
	while(i < argc) {
		Node* c = q.front();
		q.pop();
		c->left = new Node(argv[i++][0]);
		c->right = (i < argc ? new Node(argv[i++][0]) : nullptr);
		q.push(c->left);
		q.push(c->right);
	}

	print_tree(root);
	destroy(root);
	return 0;
}
