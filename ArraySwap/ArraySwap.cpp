// ArraySwap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void printVector(const std::vector<int>& A)
{
  for (auto a : A)
  {
    std::cout << a;
  }
  std::cout << std::endl;
}

std::vector<int> solution(std::vector<int>& A, int K) {
  // write your code in C++14 (g++ 6.2.0)

  if (A.empty() || A.size() == static_cast<size_t>(1) || K == static_cast<int>(A.size())) return A;

  if (K <= static_cast<int>(A.size()))
    std::rotate(A.begin(), A.end() - K, A.end());
  else
  {
    const div_t divResult = div(K, A.size());
    std::rotate(A.begin(), A.end() - divResult.rem, A.end());
  }
  return A;
}


int main()
{
    std::vector<int> E{ 1,2 };
    printVector(E);
    E = solution(E, 1);
    printVector(E);

    std::vector<int> D{  };
    printVector(D);
    D = solution(D, 3);
    printVector(D);

    std::vector<int> A {3, 8, 9, 7, 6};
    printVector(A);
    A = solution(A, 3);
    printVector(A);

    std::vector<int> B{ 0,0,0 };
    printVector(B);
    B = solution(B, 1);
    printVector(B);

    std::vector<int> C{ 1,2,3,4};
    printVector(C);
    C = solution(C, 5);
    printVector(C);
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
