cmake_minimum_required(VERSION 3.14)
project(AllProjects)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

# Declare GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory("Topic ReduceBinaryString")
add_subdirectory(SmallestPosInteger)
add_subdirectory("Topic Split Substring")
add_subdirectory("Topic Max Strings")
add_subdirectory(OddOccurrencesInArray)
add_subdirectory(GenomicRange)
add_subdirectory(TapeEquilibrium)
add_subdirectory("Missing Element")
add_subdirectory(Blank)
add_subdirectory("Cyclic Rotation")
add_subdirectory(Sorting)