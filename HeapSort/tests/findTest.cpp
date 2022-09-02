// findTest.cpp

#include <iostream>
#include "MaxHeap.h"

int main (void) {
    int n = 3;

    int numbers[7] = {0,1,2,3,4,5,6};

    MaxHeap<int>* maxheap = new MaxHeap<int>(n);
   
    int i;
    for (i=0; i<7; i++)
    {
        maxheap->insert(numbers[i]);
    }
    
    Node<int>* node5 = maxheap->findNode(5);

    if (node5 == nullptr || node5->data != 5)
        return -1;

    std::cout << "found node: " << node5->index << " data: " << node5->data << std::endl;

    Node<int>* nodeNull = maxheap->findNode(100);
    if (nodeNull == nullptr)
        std::cout << "nodeNull not found" << std::endl;
    else
        return -1;

    delete(maxheap);
    
    std::cout << "findTest passed" << std::endl;
}