// PermCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int>& A) {

  std::sort(A.begin(), A.end());

  auto vectorSize = A.size();

  if (A.size() - 1 == static_cast<size_t>(A.back() - A.front()))
  {
    return 1;
  }
  return 0;
}


int main()
{
  std::vector<int> A{ 4,1,3,2 };

    std::cout << solution(A) << "\n";

    std::vector<int> B{ 4,1,3 };


    std::cout << solution(B) << "\n";
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
