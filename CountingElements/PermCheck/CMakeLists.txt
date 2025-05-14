
cmake_minimum_required (VERSION 3.14)
project(PermCheck)

# Create library from source files
add_library(PermCheckLib 
    "PermCheck.cpp"
    "PermCheck.h"
)

# Add source to this project's executable.
add_executable (PermCheck "main.cpp")
target_link_libraries(PermCheck PRIVATE PermCheckLib)

# Add the test subdirectory
add_subdirectory(test)