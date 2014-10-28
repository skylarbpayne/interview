/**
 * Implement an algorithm to find the kth to last element of a singly linked list.
 **/

#include <iostream>

class Node
{
public:
	Node* next;
	int data;

	Node(int d, Node* n = nullptr) : next(n), data(d) { }
};

Node* kthToLast(unsigned int k, Node* list)
{
	Node* end = list;
	for(unsigned int i = 0; i < k && end->next != nullptr; ++i)
	{
		end = end->next;
	}

	Node* kthFromLast = list;
	while(end->next != nullptr)
	{
		kthFromLast = kthFromLast->next;
		end = end->next;
	}
	return kthFromLast;
}

int main(int argc, char** argv)
{
	Node* list = nullptr;
	for(unsigned int i = 0; i < 10; ++i)
	{
		list = new Node(i, list);
	}

	for(unsigned int i = 0; i < 10; ++i)
	{
		std::cout << kthToLast(i, list)->data << std::endl;
	}
}
