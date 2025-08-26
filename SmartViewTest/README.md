# SmartViewTest CMake Setup

This repository contains a CMake setup for building the SmartViewTest project.

## Prerequisites

- CMake (version 3.14 or higher)
- A C++ compiler supporting C++14 (such as Visual Studio, GCC, or Clang)

## Building with CMake from the Command Line

### Basic Usage

C:\Users\cpeddle\source\repos\codility>"C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build c:/Users/cpeddle/source/repos/codility/build --config Debug --target SmartViewTest -j 10 -- && "C:/Users/cpeddle/source/repos/codility/build/bin/Debug/SmartViewTest.exe"

From the current directory (cpp\SmartViewTest)
```powershell
# Create and navigate to the build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
cmake --build . --config Debug

# Run the executable
.\bin\Debug\SmartViewTest.exe
```

### Using Different Generators

You can specify a generator with the `-G` option:

```powershell
# Visual Studio generator
cmake -G "Visual Studio 17 2022" -A x64 ..

# MinGW Makefiles generator
cmake -G "MinGW Makefiles" ..
```
