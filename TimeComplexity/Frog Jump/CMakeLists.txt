cmake_minimum_required(VERSION 3.14)
project(FrogJump)

# Set C++14 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(FrogJump "Frog Jump.cpp")

# If you want to enable Google Test later, uncomment the following:
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)
# 
# enable_testing()
# 
# target_link_libraries(
#   FrogJump
#   GTest::gtest_main
# )
# 
# include(GoogleTest)
# gtest_discover_tests(FrogJump)