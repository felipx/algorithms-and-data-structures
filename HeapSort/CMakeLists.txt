# CMakeList.txt : CMake project for HeapSort
#
#
cmake_minimum_required (VERSION 3.8)

project ("HeapSort")

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -Werror)
endif()

# include directory 
include_directories(include)

# .cpp files
#add_executable (main "src/main.cpp" "src/Node.cpp" "src/MaxHeap.cpp")

# TESTS
add_subdirectory (tests)