// Heap.cpp: определяет точку входа для приложения.
//

#include "Heap.h"

HeapNode* Heap::parent(HeapNode* node) {
    if (node == nullptr || node->parent == nullptr) return nullptr;
    return node->parent;
}

HeapNode* Heap::leftChild(HeapNode* node) {
    if (node == nullptr) return nullptr;
    return node->left;
}

HeapNode* Heap::rightChild(HeapNode* node) {
    if (node == nullptr) return nullptr;
    return node->right;
}

void Heap::heapifyUp(HeapNode* node) {
    if (node == nullptr || node->parent == nullptr) return;
    if (node->key < node->parent->key) {
        std::swap(node->key, node->parent->key);
        heapifyUp(node->parent);
    }
}

void Heap::heapifyDown(HeapNode* node) {
    if (node == nullptr) return;

    HeapNode* smallest = node;
    HeapNode* left = leftChild(node);
    HeapNode* right = rightChild(node);

    if (left != nullptr && left->key < smallest->key) {
        smallest = left;
    }

    if (right != nullptr && right->key < smallest->key) {
        smallest = right;
    }

    if (smallest != node) {
        std::swap(node->key, smallest->key);
        heapifyDown(smallest);
    }
}

void Heap::insertNode(HeapNode* node, int key) {
    if (!node) {
        node = new HeapNode(key);
        return;
    }
    else if (!node->left) {
        node->left = new HeapNode(key);
        node->left->parent = node;
        heapifyUp(node->left);
    }
    else if (!node->right) {
        node->right = new HeapNode(key);
        node->right->parent = node;
        heapifyUp(node->right);
    }
    else {
        insertNode(node->left, key);
    }
}

int Heap::extractTop() {
    if (root == nullptr) {
        throw std::out_of_range("Heap is empty");
    }

    int topKey = root->key;

    // Перемещаем последний элемент в корень
    HeapNode* lastNode = findLastNode(root);
    root->key = lastNode->key;

    // Удаляем последний элемент
    removeNode(lastNode);

    heapifyDown(root);

    return topKey;
}

void Heap::printHeap(HeapNode* node)
{
    if (!node) return;
    else {
        std::cout << node->key << " ";
        printHeap(node->left);
        printHeap(node->right);
    }
}

void Heap::printHeap()
{
    printHeap(root);
    std::cout << std::endl;
}

HeapNode* Heap::findLastNode(HeapNode* node) {
    if (node == nullptr) return nullptr;

    if (node->left == nullptr && node->right == nullptr) return node;

    HeapNode* lastLeft = findLastNode(node->left);
    HeapNode* lastRight = findLastNode(node->right);

    return lastLeft != nullptr ? lastLeft : lastRight;
}

void Heap::removeNode(HeapNode* node) {
    if (node == nullptr) return;

    if (node->parent != nullptr) {
        if (node->parent->left == node) {
            node->parent->left = nullptr;
        }
        else {
            node->parent->right = nullptr;
        }
    }

    delete node;
}

Heap::Heap() : root(nullptr) {}

Heap::Heap(const std::vector<int>& data)
{
    root = new HeapNode(data[0]);
    for (size_t i = 1; i < data.size(); ++i) {
        insert(data[i]);
    }
}

void Heap::insert(int key) {
    insertNode(root, key);
}

