// CodeSignal_Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <vector>

inline void printVector(const std::vector<int>& _vector) {
  for (auto i = _vector.begin(); i != _vector.end(); i++)
    std::cout << std::setw(2) << *i << ' ';
}

std::vector<int> mutateTheArray(int n, std::vector<int> a) {
  std::vector<int> b;

  for (auto i = 0; i < n; ++i)
  {

    auto minI = 0;
    if (i - 1 >= 0 && i - 1 < a.size()) minI = a.at(i - 1);

    auto atI = 0;
    if (i < a.size()) atI = a.at(i);

    auto plusI = 0;
    if (i + 1 < a.size()) plusI = a.at(i + 1);

    auto value = minI + atI + plusI;

    b.push_back(value);
  }

  return b;
}



int countWaysToSplit(std::string s) {

  return 0;
}

int main()
{
  std::vector<int> a { 4,0,1,0 - 2,3 };
  printVector(mutateTheArray(5, a));

  std::vector<int> b{ 4,0,1,0 - 2,3 };
  printVector(mutateTheArray(5, a));

    std::cout << "Hello World!\n";
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
