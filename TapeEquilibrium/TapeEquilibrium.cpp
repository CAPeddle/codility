// TapeEquilibrium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& A)
{
  for (auto a : A)
  {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}

int solution(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)

  if (A.size() == 2) return abs(A.front() - A.back());

  std::vector<int> B(A.size(),0);
  std::partial_sum(A.begin(), A.end(), B.begin(), std::plus<>());


  std::vector<int> results;
  for (size_t i = 0; i < B.size(); ++i)
  {
    auto value = abs(B.back() - (2 * B.at(i)));
    //if (value == 1) return i + 1;
    results.push_back(value);
  }

  printVector(A);
  printVector(B);
  printVector(results);

  return *std::min_element(results.begin(), results.end());
}

int main()
{
  
  std::vector<int> A {3, 1, 2, 4, 3}; 
  std::cout << "A\n" << solution(A) << "\n\n\n";
    
  std::vector<int> B{ 3, 1 };
  std::cout << "B\n" << solution(B) << "\n\n\n";

  std::vector<int> E{ -1000, 1000 };
  std::cout << "E\n" << solution(E) << "\n\n\n";

  std::vector<int> C{ 3, 1, 2, 4, 3 };
  std::cout << "C\n" << solution(C) << "\n\n\n";

  // std::vector<int> D( 100000, 6 );
  // std::cout << "D" << solution(D) << "\n\n\n";

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
