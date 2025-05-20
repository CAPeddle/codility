# CMakeList.txt : CMake project for MinAvgTwoSlices, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(MinAvgTwoSlices)

# Create library from source files
add_library(MinAvgTwoSlicesLib 
    "MinAvgTwoSlices.cpp"
    "MinAvgTwoSlices.h"
)

# Add source to this project's executable.
add_executable (MinAvgTwoSlices "main.cpp")
target_link_libraries(MinAvgTwoSlices PRIVATE MinAvgTwoSlicesLib)

# Add the test subdirectory
add_subdirectory(test)
