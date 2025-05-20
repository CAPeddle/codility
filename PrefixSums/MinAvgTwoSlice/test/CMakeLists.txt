cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(MinAvgTwoSlicesTest 
    "MinAvgTwoSlicesTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(MinAvgTwoSlicesTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(MinAvgTwoSlicesTest gtest_main)
target_link_libraries(MinAvgTwoSlicesTest 
    PRIVATE
    gtest_main
    MinAvgTwoSlicesLib
)

# target_link_libraries(MinAvgTwoSlicesTest gtest_main)
add_test(NAME MinAvgTwoSlicesTest COMMAND MinAvgTwoSlicesTest)


