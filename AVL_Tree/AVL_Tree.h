#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>

struct Node {
	int value;
	int height;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int value) : value(value), height(1) {};
};

class AVLTree {
private:
	Node* root = nullptr;

	int nodeCount = 0;

	int height(Node* node) {
		if (!node) return 0;
		return node->height;
	}

	int balanceFactor(Node* node) {
		if (!node) return 0;
		return height(node->right) - height(node->left);
		//should be -1 if leftHeight > rightHeight 
		//should be 0 if leftHeight = rightHeight
		//should be 1 if leftHeight < rightHeight
		//if <-1 : rightPivot(Node* node)
		//if >1 :  leftPivot(Node* node)
	}

	void updateHeight(Node* node) {
		if (node) {
			node->height = std::max(height(node->left), height(node->right)) + 1;
		}
	}

	Node* findMin(Node* node);
	
	Node* rightPivot(Node* p);

	Node* leftPivot(Node* q);

	Node* balance(Node* node);

	Node* removeMin(Node* node); 
	
	Node* removeRecursive(Node* node, int value);

	Node* addRecursive(Node* node, int value);


public:
	AVLTree() = default;

	AVLTree(int value) { root = new Node(value); nodeCount = 1; }

	~AVLTree() { delete root; nodeCount = 0; }

	AVLTree(AVLTree& rhs) { this->root = rhs.root; this->nodeCount = rhs.nodeCount; }

	AVLTree(AVLTree&& rhs) noexcept { this->root = rhs.root; this->nodeCount = rhs.nodeCount; rhs.root = nullptr; }

	bool has(int value) noexcept { return findValue(value); }

	Node* findValue(int value);

	void add(int value);

	void add(int* values, int len);

	void remove(int value);

	int max();
	
	int min();

	int getHeight() { updateHeight(root); return height(root); }

	int balanceCheck1() { return balanceFactor(root); }

	double balanceCheck2() { return 1.45 * std::log2(nodeCount + 2); }

	int rootValue() { return root->value; }

	Node* getRoot() { return root; }

	int getNodes() { return nodeCount; }
};