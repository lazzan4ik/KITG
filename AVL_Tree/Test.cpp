#include "AVL_Tree.h"

void printTree(Node* node, int level = 0) {
	if (node) {
		printTree(node->right, level + 1);
		for (int i = 0; i < level; i++) {
			std::cout << "  ";
		}
		std::cout << node->value << std::endl;
		printTree(node->left, level + 1);
	}
}

int main() {
	AVLTree bst;
	int len = 1024;
	int* f = new int[len];
	int x = -rand() % 6 + rand() % 9 + 3 - rand() % 5 + rand() % 4;
	for (int i = 0; i < len; ++i) {
		x += -rand() % 6 + rand() % 9 + 3 - rand() % 5 + rand() % 4 - rand() % 3;
		if (x == 0) x = rand() % 300 + 1;
		f[i] = x;
	}
	bst.add(f, len);
	printTree(bst.getRoot()); //function to show the tree, more actual on len(7-15) 
	//If it's correct, the height should be log2(nodeCount) round on top and << balance verdict
	std::cout << "Tree ABOVE" << std::endl;
	std::cout << "BALANCE FACTOR: " << bst.balanceCheck1() << std::endl;
	std::cout << "BALANcE VERDICT: " << bst.balanceCheck2() << std::endl;
	std::cout << "HEIGHT: " << bst.getHeight() << std::endl;
	std::cout << "NODES: " << bst.getNodes() << std::endl;
	std::cout << "IT HAS 1625: " << bst.has(1625) << std::endl;
	std::cout << "The first-origin list:" << std::endl;
	for (int i = 0; i < len; ++i) {
		std::cout << f[i] << " ";
	}
	
}