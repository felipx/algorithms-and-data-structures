// MaxHeap.cpp

/***********************************************************************************
 * This file is part of HeapSort Algorithm                                         *
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

#include "MaxHeap.h"

/*
* Constructor.
*/
template <class T> MaxHeap<T>::MaxHeap(int k) : n(k), counter(0)
{
    root = new Node<T>();
    root->index = 0;
    root->parent = nullptr;
}


/*
* Destructor.
*/
template <class T> MaxHeap<T>::~MaxHeap()
{
    std::queue<Node<T>*> q;
    store(root, &q);
    while (!q.empty())
    {
        Node<T>* n = q.front();
        q.pop();
        delete n;
    }
}


/*
* Store all nodes in queue 'q'. Called in destructor.
*/
template <class T> void MaxHeap<T>::store(Node<T>* node, std::queue<Node<T>*>* q) 
{
    if (node->index == 0)
        q->push(node);
    for (Node<T>* child : node->children)
    {
        q->push(child);
        store(child, q);   
    }
}


/*
* Inserts a new node. Calls heapify to keep maxheap structure.
*/
template <class T> void MaxHeap<T>::insert(T x) 
{
    if (counter == 0)
    {
        root->data = x;
        counter++;
        auxQueue.push(root);
        return;
    }
    Node<T>* newNode = new Node<T>();
    newNode->data = x;
    newNode->parent = auxQueue.front();
    newNode->index = counter++;
    auxQueue.front()->children.push_back(newNode);
    auxQueue.push(newNode);
    auxStack.push(newNode);
    heapify(newNode);
    if ( (counter - 1) % n == 0 )
        auxQueue.pop();
}


/*
* Traverses a branch from node to root node, keeping the highest data value of the branch in root node. 
*/
template <class T> void MaxHeap<T>::heapify(Node<T>* node) 
{
    if (node->index > 0)
    {
        if (node->data > node->parent->data)
            swap(node, node->parent);
        heapify(node->parent);
    }
}


/*
* Swaps values between nodes.
*/
template <class T> void MaxHeap<T>::swap(Node<T>* a, Node<T>* b) 
{
    T temp = a->data;
    a->data = b->data;
    b->data = temp;
}


/*
* Sorts the data in the tree.
*/
template <class T> void MaxHeap<T>::heapSort() 
{
    while (!auxStack.empty())
    {
        swap(root, auxStack.top());
        auxStack.top()->sorted = true;
        auxStack.pop();
        siftDown(root);
    }
}


/*
* Traverses a branch from node to leaf node, swaping data if a child node has a higher data than parent node. 
*/
template <class T> void MaxHeap<T>::siftDown(Node<T>* node)
{
    Node<T>* max = compare(node);
    if (node->data < max->data) 
        swap(node, max);
    for (Node<T>* child : node->children) {
        if (child != nullptr) {
            siftDown(child);
        }
    }
}


/*
* Compares the data of a node with the data its children nodes. Returns pointer to highest data value node.
*/
template <class T> Node<T>* MaxHeap<T>::compare(Node<T>* node)
{
    Node<T>* max = node;
    if (!node->children.empty()) {
        for (Node<T>* child : node->children)
        {
            if (child != nullptr && !child->sorted)
            {
                if ( max->data <= child->data)
                {
                    max = child;
                }
            }
        }
    }
    return max;
}


/*
* Returns pointer no node with data 'd'. If node doesn't exists, returns nullptr.
*/
template <class T> Node<T>* MaxHeap<T>::findNode(T d) 
{
    std::queue<Node<T>*> q;
    return find(root, q, d);
}

template <class T> Node<T>* MaxHeap<T>::find(Node<T>* node, std::queue<Node<T>*>q, T d) 
{
    if (node->index == 0 && node->data == d)
        return root;
    for (Node<T>* child : node->children)
    {
        q.push(child);
        if (child->data == d)
            return child;
    }
    if (!q.empty())
    {
        Node<T>* n = q.front();
        q.pop();
        find(n, q, d);
    }
    return nullptr;
}


/*
* Prints maxheap node list in console window.
*/
template <class T> void MaxHeap<T>::printHeap() 
{
    std::cout << std::endl;
    std::queue<Node<T>*> q;
    print(root, q);
}

template <class T> void MaxHeap<T>::print(Node<T>* node, std::queue<Node<T>*>q) 
{
    if (node->index == 0)
        std::cout << "Root " << root->index << " - Data: " << root->data << std::endl;
    for (Node<T>* child : node->children)
    {
        q.push(child);
        std::cout << "Node " << child->index << " - Data: " << child->data << " - Parent: " << child->parent->index << std::endl;   
    }
    if (!q.empty())
    {
        Node<T>* n = q.front();
        q.pop();
        print(n, q);
    }
}


/*
* Prints maxheap stored data in file.
*/
template <class T> void MaxHeap<T>::printDataInFile(std::string fname) 
{
    std::fstream* f = new std::fstream;
    f->open(fname, std::fstream::out);
    std::queue<Node<T>*> q;
    printInFile(root, q, f);
}

template <class T> void MaxHeap<T>::printInFile(Node<T>* node, std::queue<Node<T>*>q, std::fstream* f) 
{
    if (node->index == 0)
        *f << root->data << std::endl;
    for (Node<T>* child : node->children)
    {
        q.push(child);
        *f << child->data << std::endl;   
    }
    if (!q.empty())
    {
        Node<T>* n = q.front();
        q.pop();
        printInFile(n, q, f);
    }
    else
    {
        f->close();
        delete(f);
    }
}


template <class T> Node<T>* MaxHeap<T>::getRoot()
{
    return this->root;
}

template class MaxHeap<char>;
template class MaxHeap<int>;
template class MaxHeap<long>;
template class MaxHeap<long long>;
template class MaxHeap<unsigned int>;
template class MaxHeap<unsigned long>;
template class MaxHeap<unsigned long long>;
template class MaxHeap<float>;
template class MaxHeap<double>;
template class MaxHeap<std::string>;