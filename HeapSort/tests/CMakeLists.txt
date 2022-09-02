# CMakeList.txt : CMake project for HeapSort
#
#
cmake_minimum_required (VERSION 3.8)

project ("HeapSort")

add_executable (insertTest "insertTest.cpp" "../src/Node.cpp" "../src/MaxHeap.cpp")
add_executable (printTest "printTest.cpp" "../src/Node.cpp" "../src/MaxHeap.cpp")
add_executable (heapSortTest "heapSortTest.cpp" "../src/Node.cpp" "../src/MaxHeap.cpp")
add_executable (findTest "findTest.cpp" "../src/Node.cpp" "../src/MaxHeap.cpp")
add_executable (printInFileTest "printInFileTest.cpp" "../src/Node.cpp" "../src/MaxHeap.cpp")
add_executable (wordsSortTest "wordsSortTest.cpp" "../src/Node.cpp" "../src/MaxHeap.cpp")