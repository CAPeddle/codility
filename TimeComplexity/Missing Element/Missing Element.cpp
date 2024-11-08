// Missing Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& A, bool _addEndLine = true)
{
  for (auto a : A)
  {
    std::cout << a << " ";
  }
  if (_addEndLine)  std::cout << std::endl;
}

int solutionA(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)
  if (A.size() < 2) return 1;

  std::sort(A.begin(), A.end());

  if (A.front() > 1) return 1;

  int lastValue(1);
  int difference(1);
  auto findElement = A.begin();
  do
  {
    difference = *findElement - lastValue;
    if (difference > 1) return lastValue + 1;

    lastValue = *findElement;
    ++findElement;
  }
  while (findElement != A.end());

  return *findElement - 1;
}

int solution(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)

  std::sort(A.begin(), A.end());
  printVector(A, false);

  if (A.empty()) return 1;
  if (A.size() == 1) return 2;

  std::vector<int> buckets(A.back(), 0);

  for (auto a : A)
  {
    ++buckets[a-1];
  }

  const auto location = std::find(buckets.rbegin(), buckets.rend(), 0);

  const auto sizeOfA            = A.size();
  const auto aback              = A.back();
  const auto backDistanceToZero = std::distance(buckets.rbegin(), location);
    
  std::cout << "\t\t\t sizeof:" << sizeOfA << " aBack:" << aback << " distanceToZero:" << backDistanceToZero << " ";

  if ((static_cast<int>(A.size()) == A.back()) && (A.back() == backDistanceToZero)) return A.back() + 1;

  return A.back() - std::distance(buckets.rbegin(), location);
}

int main()
{

    std::vector<int> A = { 2,3,1,5 };
    std::cout << "expecting 4 " << solution(A) << "\n";

    A = { 2,3,1,4,5 };
    std::cout << "expecting 6 " << solution(A) << "\n";

    /*
    A = { 2 };
    std::cout << "expecting 1 " << solution(A) << "\n";

    A = { 1 };
    std::cout << "expecting 2 " << solution(A) << "\n"; //this should return a 2
    */

    A = { 3,2 };
    std::cout << "expecting 1 " << solution(A) << "\n";

    A = { 1,2,3,4,5,6,7,8,10 };
    std::cout << "expecting 9 " << solution(A) << "\n";

    A = { 1,2,3,4,5,6,7,8,9 };
    std::cout << "expecting 10 " << solution(A) << "\n";

    A = { 2,3,4,5,6,7,8,9,10 };
    std::cout << "expecting 1 " << solution(A) << "\n";

    A = { 99998,99999,100000,100002 };
    std::cout << "expecting 100001 " << solution(A) << "\n";


  //   std::vector<int> B;
  //   B.reserve(100002);
  // for (int i = 1; i < 100002; ++i)
  // {
  //   if (i != 100002) B.push_back(i);
  // }
  //   std::cout << solution(B) << "\n";

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
