// heapSortTest.cpp

#include <iostream>
#include "MaxHeap.h"

int main (void) {
    int n = 3;
    
    int numbers[7] = {0,3,6,1,5,2,4};

    MaxHeap<int>* maxheap = new MaxHeap<int>(n);

    int i;
    for (i=0; i<7; i++)
    {
        maxheap->insert(numbers[i]);
    }

    maxheap->heapSort();

    if (maxheap->getRoot()->data != 0)
        return -1;
    
    i = 1;
    for (Node<int>* child : maxheap->getRoot()->children)
    {
        if (child->data != i)
            return -1;
        i++;
    }

    i = 4;
    for (Node<int>* child : maxheap->getRoot()->children.front()->children)
    {
        if (child->data != i)
            return -1;
        i++;
    }
    
    maxheap->printHeap();
    
    delete(maxheap);

    std::cout << "heapSortTest passed" << std::endl;
}