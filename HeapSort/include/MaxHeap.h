// MaxHeap.h

/***********************************************************************************
 * This file is part of HeapSort Algorith                                          *
 *                                                                                 *
 * Copyright (C) 2022 felipx                                                       *
 * https://github.com/felipx/                                                      *
 *                                                                                 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy    *
 * of this software and associated documentation files (the "Software"), to deal   *
 * in the Software without restriction, including without limitation the rights    *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is           *
 * furnished to do so, subject to the following conditions:                        *
 * The above copyright notice and this permission notice shall be included in all  *
 * copies or substantial portions of the Software.                                 *
 *                                                                                 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 * SOFTWARE.                                                                       *
 ***********************************************************************************/

#ifndef HEADERS_MAXHEAP_ 
#define HEADERS_MAXHEAP_

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
#include "Node.h"


/*
* Dynamic n-ary MaxHeap tree with heapsort method.
*/
template <class T> class MaxHeap 
{
private:
    int n;                            // Tree order
    int counter;                      // Number of elements in tree
    std::queue<Node<T>*> auxQueue;    // Aux queue. New nodes are added to front.
    std::stack<Node<T>*> auxStack;    // Aux stack. Holds all nodes. Used in heapsort.
    Node<T>* root;                    // root node
    
public:
    MaxHeap(int);
    ~MaxHeap();
    void insert(T x);
    void heapify(Node<T>*);
    void siftDown(Node<T>*);
    void heapSort();
    void swap(Node<T>*, Node<T>*);
    void printHeap();
    void store(Node<T>*, std::queue<Node<T>*>*);
    void printDataInFile(std::string);
    Node<T>* findNode(T);
    Node<T>* compare(Node<T>*);
    Node<T>* getRoot();

private:
    void print(Node<T>*, std::queue<Node<T>*>);
    void printInFile(Node<T>*, std::queue<Node<T>*>, std::fstream*);
    Node<T>* find(Node<T>*, std::queue<Node<T>*>, T); 
};


#endif /* HEADERS_MAXHEAP_ */
