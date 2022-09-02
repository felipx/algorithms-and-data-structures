// printInFileTest.cpp

#include <iostream>
#include "MaxHeap.h"

int main (void) {
    int n = 3;
    
    int numbers[20] = {0,6,7,44,9,3,22,67,88,95,89,33,11,54,21,90,65,32,12,55};

    MaxHeap<int>* maxheap = new MaxHeap<int>(n);

    int i;
    for (i=0; i<20; i++)
    {
        maxheap->insert(numbers[i]);
    }

    maxheap->printDataInFile("test.txt");
    
    delete(maxheap);

    std::cout << "printInFileTest passed" << std::endl;
}