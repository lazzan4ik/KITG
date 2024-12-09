#include "Heap.h"

int main() {
    std::vector<int> arr = { 10,64,2,3,5,7,1,23 };
    Heap minHeap(arr);
    minHeap.insert(6);

    std::cout << "min-Heap: ";
    minHeap.printHeap();

    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;
    std::cout << "Extracted min: " << minHeap.extractTop() << std::endl;

    std::cout << "min-Heap after extraction: ";
    minHeap.printHeap();

    return 0;
}