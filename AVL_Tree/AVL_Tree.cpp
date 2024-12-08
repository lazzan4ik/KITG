#include "AVL_Tree.h"

Node* AVLTree::findValue(int value)
{
	Node* coursor = this->root;
	while (coursor) {
		if (value < coursor->value) {
			coursor = coursor->left;
		}
		else if (value > coursor->value) {
			coursor = coursor->right;
		}
		else {
			return coursor;
		}
	}
	return nullptr; 
}

void AVLTree::add(int value)
{
	if (!this->root) this->root = new Node(value);
	else {
		this->root = addRecursive(root, value);
		nodeCount++;
	}
}

void AVLTree::add(int* values, int len)
{
	for (int i = 0; i < len; i++) {
		if (!this->root) this->root = new Node(values[i]);
		this->root = addRecursive(root, values[i]);
	}
}

void AVLTree::remove(int value)
{
	this->root = removeRecursive(root, value);
	updateHeight(root);
}

int AVLTree::max()
{
	Node* coursor = root;
	while (coursor->right) {
		coursor = coursor->right;
	}
	return coursor->value;
}

int AVLTree::min()
{
	Node* coursor = root;
	while (coursor->left) {
		coursor = coursor->left;
	}
	return coursor->value;
}

Node* AVLTree::findMin(Node* node)
{
	while (node->left) {
		node = node->left;
	}
	return node;
}

Node* AVLTree::rightPivot(Node* p)
{
	Node* q = p->left; //q - левый ребенок p (изначально)
	p->left = q->right;
	q->right = p; //p - правый ребенок q (стал) 
	updateHeight(q);
	updateHeight(p);
	return q; //новый родительский узел
}

Node* AVLTree::leftPivot(Node* q)
{
	Node* p = q->right; //p - правый ребенок q (изначально)
	q->right = p->left;
	p->left = q; //q - левый ребенок p (стал) 
	updateHeight(q);
	updateHeight(p);
	return p; //новый родительский узел 
}

Node* AVLTree::balance(Node* node)
{
	updateHeight(node);
	if (balanceFactor(node) > 1) {
		if (balanceFactor(node->right) < 0) {
			node->right = rightPivot(node->right);
		}
		return leftPivot(node);
	}
	if (balanceFactor(node) < -1) {
		if (balanceFactor(node->left) > 0) {
			node->left = leftPivot(node->left);
		}
		return rightPivot(node);
	}
	return node;
}

Node* AVLTree::removeMin(Node* node)
{
	if (node->left == nullptr) {
		Node* tmp = node->right;
		return tmp;
	}
	node->left = removeMin(node->left);
	return balance(node);
}

Node* AVLTree::removeRecursive(Node* node, int value)
{
	if (!node) { 
		std::cout << "There is no such value in Tree" << std::endl;
		return node; 
	}

	if (value < node->value) {
		node->left = removeRecursive(node->left, value);
	}
	else if (value > node->value) {
		node->right = removeRecursive(node->right, value);
	}
	else {
		Node* left = node->left;
		Node* right = node->right;
		delete node;
		if (!right) return left;
		Node* min = findMin(right);
		min->right = removeMin(right);
		min->left = left;
		Node* tree = balance(min);
		nodeCount--;
		return(balance(min));
	}
	return balance(node);
}

Node* AVLTree::addRecursive(Node* node, int value)
{
	if (!node) { 
		nodeCount++; 
		return new Node(value); 
	}

	if (value < node->value) {
		node->left = addRecursive(node->left, value);
	}
	else if (value > node->value) { 
		node->right = addRecursive(node->right, value); 
	}
	return balance(node);
}