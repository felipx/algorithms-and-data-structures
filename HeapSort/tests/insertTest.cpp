// insertTest.cpp

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
    
    if (maxheap->getRoot()->data != 6)
        return -1;
    
    i = 5;
    for (Node<int>* child : maxheap->getRoot()->children)
    {
        if (child->data != i)
            return -1;
        if (i == 1)
            i = 2;
        if (i == 5)
            i = 1;  
    }

    i = 0;
    for (Node<int>* child : maxheap->getRoot()->children.front()->children)
    {
        if (child->data != i)
            return -1;
        if (i == 3)
            i = 4;
        if (i == 0)
            i = 3;   
    }

    delete(maxheap);

    std::cout << "insertTest passed" << std::endl;
}