// ASML Jonathan.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// 
/*
Write a method:
public int IsXDivisibleByY(int X, int Y) { ​ ... }​
That meets the following conditions :
1. Method returns 1, if X can be divided by Y without a remainder.
2. Method returns 0, if X can't be divided by Y without a remainder.
3. Solution MUSN'T include any conditional checks (if condition, equality operators, the ternary and null coalescing operators, etc.).
4. Solution MUSN'T include any exception handling (try catch finally)
5. It must be taken into account that both parameters could be given all range of the parameter type.
*/
// 
//

#include <iostream>


int IsXDivisibleByY(int X, int Y)
{
  auto mod = (int)fmod(X, (double)Y);
  auto accumulator = 0;
  for (auto i = 0; i < 32; i++)
  {
    accumulator |= (mod & 1);
    mod >>= 1;
  }
  return accumulator ^ 1;
}

int main()
{
  std::cout << 1 << "/" << INT_MAX << ":" << IsXDivisibleByY(1, INT_MAX) << "\n";
  std::cout << INT_MAX << "/" << INT_MAX << ":" << IsXDivisibleByY(INT_MAX, INT_MAX) << "\n";
  std::cout << INT_MAX << "/" << 0 << ":"<< IsXDivisibleByY (INT_MAX, 0) << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
