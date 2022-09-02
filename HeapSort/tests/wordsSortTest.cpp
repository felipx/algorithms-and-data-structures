// wordsSortTest.cpp

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <random>
#include "MaxHeap.h"

void generateWords(int);
std::string random_string(std::size_t);

int main (void) {
    int n = 5;
    int N = 10000;

    MaxHeap<std::string>* maxheap = new MaxHeap<std::string>(n);

    generateWords(N);

    std::fstream f;
    std::string word;
    f.open("words.txt", std::fstream::in);

    while (f >> word)
    {
        maxheap->insert(word);
    }
    
    f.close();

    maxheap->heapSort();
    maxheap->printDataInFile("sortedWords.txt");

    f.open("sortedWords.txt", std::fstream::in);
    
    std::string previous;
    std::string next;
    int i = 0;
    while (f >> word)
    {
        if (i == 0)
        {
            next = word;
            i++;
        }
        else
        {
            previous = next;
            next = word;
            if (previous > next)
            {
                std::cout << "wordsSortTest failed" << std::endl;
                return -1;
            }
        }
    }
    f.close();

    delete(maxheap);

    std::cout << "wordsSortTest passed" << std::endl;
}


void generateWords(int n)
{
    std::fstream f;
    f.open("words.txt", std::fstream::out);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1,10);
    int numAleatorio;
    while (n > 0) {
        numAleatorio = distribution(generator);
        f << random_string( (std::size_t) numAleatorio ) << std::endl;
        n--;
    }    
    f.close();
}

std::string random_string(std::size_t s)
{
    static const std::string chars = "abcdefghijklmnopqrstuvwxyz" ;
    static std::default_random_engine rng( std::time(nullptr) ) ;
    static std::uniform_int_distribution<std::size_t> dist( 0, chars.size() - 1 ) ;

    std::string str ;
    while( str.size() < s ) str += chars[ dist(rng) ] ;
    return str ;
}