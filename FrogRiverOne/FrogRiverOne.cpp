// FrogRiverOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <vector>
#include <iostream>
int solution(int X, std::vector<int>& A) {

  //search for each position and store it's index, when all the indexes are stored, highest number is earliest
  // X - t
  // -----
  // 1 - 0
  // 2 - 4
  // 3 - 1
  // 4 - 3
  // 5 - 6
  //
  //

    std::vector<int> leafTimes;
    for (auto i = 1; i<=X; ++i)
    {
      auto indexOfLeaf = std::find(A.begin(), A.end(), i);
      if (indexOfLeaf == A.end()) return -1;
      leafTimes.push_back(indexOfLeaf - A.begin());
    }

    std::sort(leafTimes.begin(), leafTimes.end());

    return leafTimes.back();
}

int main()
{
    std::vector<int> A{ 1,3,1,4,2,3,5,4 };

    std::cout << solution(5,A) << "\n";
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
