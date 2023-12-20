#include "heap.h"
#include <iostream>


int main() {
    MaxHeap heap;

    heap.load({4, 1, 3, 2, 16, 9, 10, 14, 8, 7});

    std::cout << heap.isMaxHeap() << "\n";

    heap.buildMaxHeap();
    
    std::cout << heap.isMaxHeap() << "\n";

    return 0;
}