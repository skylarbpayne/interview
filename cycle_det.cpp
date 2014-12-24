/**
 * Author: Skylar Payne
 * Date: December 24, 2014
 * Detect if there is a cycle in a given connected, directed graph
 **/

#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

class Node {
public:
	std::vector<Node*> adj;
};

bool is_cyclic(Node* root) {
	if(root == nullptr) {
		return false;
	}
	std::set<Node*> visited;
	visited.insert(root);
	for(int i = 0; i < root->adj.size(); ++i) {
		if(visited.find(root->adj[i]) == visited.end() || is_cyclic(root->adj[i])) {
			return true;
		}
		visited.insert(root->adj[i]);
	}
	return false;
}

int main(int argc, char** argv) {
	Node graph1[10];
	Node graph2[10];
	Node graph3[10];
	Node graph4[10];
	for(int i = 1; i < 10; ++i) {
		graph1[i].adj.push_back(&graph1[i - 1]);
	}
	for(int i = 1; i < 10; ++i) {
		graph2[i].adj.push_back(&graph2[0]);
	}
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < i; ++j) {
			graph3[i].adj.push_back(&graph3[j]);
		}
	}
	for(int i = 1; i < 10; ++i) {
		graph4[i].adj.push_back(&graph4[i - 1]);
		graph4[i - 1].adj.push_back(&graph4[i]);
	}

	assert(is_cyclic(&graph1[0]) == false);
	assert(is_cyclic(&graph2[0]) == false);
	assert(is_cyclic(&graph3[0]) == false);
	assert(is_cyclic(&graph4[0]) == true);
	std::cout << "Tests passed" << std::endl;

	return 0;
}
