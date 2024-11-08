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
set(EXCLUDED_DIRS "ASML Jonathan" ".github" "Helpers" "TotalJan2021" "CountingElements" "Iterations" ".git" ".vscode")

file(GLOB subdirs RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(subdir ${subdirs})
  if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${subdir} AND NOT EXISTS ${CMAKE_SOURCE_DIR}/${subdir}/.git)
    list(FIND EXCLUDED_DIRS ${subdir} index)
    if(index EQUAL -1)
      add_subdirectory(${subdir})
    endif()
  endif()
endforeach()