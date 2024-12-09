// Heap.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <vector>


struct HeapNode {
    int key;
    HeapNode* left;
    HeapNode* right;
    HeapNode* parent;

    HeapNode(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Heap {
private:

    HeapNode* root;

    HeapNode* parent(HeapNode* node);
    HeapNode* leftChild(HeapNode* node);
    HeapNode* rightChild(HeapNode* node);

    void heapifyUp(HeapNode* node);
    void heapifyDown(HeapNode* node);
    void insertNode(HeapNode* node, int key);
    HeapNode* findLastNode(HeapNode* node);
    void removeNode(HeapNode* node);
    void printHeap(HeapNode* node);

public:
    Heap();
    Heap(const std::vector<int>& data);
    void insert(int key);
    int extractTop();
    void printHeap();
};