// PrefixSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "C:\Users\cpeddle\source\repos\Codility\Total Codility Test\AuxiliaryFunctions.h"


std::vector<int> prefix_sums(std::vector<int> _a)
{
  if (_a.empty() || _a.size() == 1) return _a;

  const size_t n = _a.size();
  std::vector<int> P;
  try
  {
    P.push_back(_a.at(0));
    for (size_t i = 1; i < n; ++i)
    {
      int pkMin1 = P.at(i - 1);
      int akMin1 = _a.at(i - 1);
      P.push_back(P.at(i - 1) + _a.at(i));
    }    
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << "\n";
  }
  return P;
}
/*
n = len(A)
P = [0] * (n + 1)
for k in xrange(1, n + 1) :
P[k] = P[k - 1] + A[k - 1]
return P
 */

int count_total(const std::vector<int>& _a, const int &_x, const int &_y)
{
  if (_a.size() < _y + 1) throw std::invalid_argument("Invalid Y value");
  if (_a.size() < _x) throw std::invalid_argument("Invalid X value");

  return _a.at(_y + 1) - _a.at(_x);
}

//def count_total(P, x, y) :
// return P[y + 1] - P[x]

//picker starts at spot k = 4 and should perform m = 6 moves
int mushrooms(std::vector<int> A, int k, int m)
{
  int n = static_cast<int>(A.size());
  int result = 0;
  auto pref = prefix_sums(A);
  const auto mkMin = static_cast<int>(std::min(m, k));
  for (int p = 0; p <= mkMin + 1; ++p)
  {
    int left_pos = k - p;
    int right_pos = std::min(n - 1, std::max(k, k + m - 2 * p));
    result = std::max(result, count_total(pref, left_pos, right_pos));
  }
  const auto minMpK = static_cast<int>(std::min(m + 1, n - k));

  for (int p = 0; p <= minMpK; ++p)
  {
    int right_pos = k + p;
    int left_pos = std::max(0, std::min(k, k - (m - 2 * p)));

    result = std::max(result, count_total(pref, left_pos, right_pos));
  }

  return result;
}
/*
  n = len(A)
  result = 0
  pref = prefix_sums(A)
  for p in xrange(min(m, k) + 1) :
    left_pos = k - p
    right_pos = min(n - 1, max(k, k + m - 2 * p))
    result = max(result, count_total(pref, left_pos, right_pos))
    for p in xrange(min(m + 1, n - k)) :
      right_pos = k + p
      left_pos = max(0, min(k, k - (m - 2 * p)))
      result = max(result, count_total(pref, left_pos, right_pos))
      return result
      */
int main()
{
                    //   0 1 2 3 4 5 6
  std::vector<int> A = { 2,3,7,5,1,3,9 };
  try
  {
    auto pref = prefix_sums(A);
    printVector(A);
    std::cout << "\n";
    printVector(pref);
    std::cout << "\n";
    auto count = count_total(pref, 0, 6);

    std::cout << count << "\n";
    std::cout << mushrooms(A, 4, 6);    
  }
  catch (std::exception e)
  {
    std::cout << "BAD " << e.what();
  }
  catch (...)
  {
    std::cout << "BAD";
  }
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
