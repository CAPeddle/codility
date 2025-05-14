cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(PermCheckTest 
    "PermCheckTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(PermCheckTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(PermCheckTest gtest_main)
target_link_libraries(PermCheckTest 
    PRIVATE
    gtest_main
    PermCheckLib
)

# target_link_libraries(PermCheckTest gtest_main)
add_test(NAME PermCheckTest COMMAND PermCheckTest)


