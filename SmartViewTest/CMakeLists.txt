cmake_minimum_required(VERSION 3.14)
project(SmartViewTest VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to C++14 (or adjust according to your needs)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type settings
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Define the source files
set(SOURCES
    SmartViewTest/SmartViewTest.cpp
)

# Define the header files
set(HEADERS
    SmartViewTest/DataSet.h
    SmartViewTest/Entity.h
    SmartViewTest/Helpers.h
)

# Create the executable
add_executable(SmartViewTest ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(SmartViewTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SmartViewTest)

# Set compiler flags based on the build type
if(MSVC)
    target_compile_options(SmartViewTest PRIVATE /W4 /EHsc)
    # Add Debug-specific flags
    target_compile_options(SmartViewTest PRIVATE $<$<CONFIG:Debug>:/Od /Zi>)
    # Add Release-specific flags
    target_compile_options(SmartViewTest PRIVATE $<$<CONFIG:Release>:/O2>)
else()
    target_compile_options(SmartViewTest PRIVATE -Wall -Wextra -pedantic)
    # Add Debug-specific flags
    target_compile_options(SmartViewTest PRIVATE $<$<CONFIG:Debug>:-O0 -g>)
    # Add Release-specific flags
    target_compile_options(SmartViewTest PRIVATE $<$<CONFIG:Release>:-O3>)
endif()

# Set output directories
set_target_properties(SmartViewTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)