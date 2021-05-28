// CodilityTest Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>


int binarySolution(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)

  if (A.empty()) return 1;
  std::sort(A.begin(), A.end());

  int leftLimit = 0, rightLimit = A.size() - 1;

  // perform binary search to find missing
  while (leftLimit <= rightLimit) {
    int middle = (leftLimit + rightLimit) / 2;

    // Element at index `i` should be
    // `i+1` (e.g. 1 at index 0). If
    // this is the first element 
    // which is not `i`+ 1, then 
    // missing element is middle+1 
    if (A[middle] != middle + 1 &&
      A[middle - 1] == middle)
      return middle + 1;

    // If this is not the first missing 
    // element search in left subarray 
    if (A[middle] != middle + 1)
      // update rightLimit to search only left
      rightLimit = middle - 1;

    // if it follows index+1 property then 
    // search in right side 
    else
      // update leftLimit to search only right
      leftLimit = middle + 1;
  }

  // Not found? No element is missing 
  return -1;
}

int solution(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)

  if (A.empty()) return 1;

  std::sort(A.begin(), A.end());

  if (A.back() < 1) return 1;

  int searchElement = 0;
  const auto minimumValueOverZero = std::lower_bound(A.begin(), A.end(), 0);
  if (*minimumValueOverZero > 1) return 1;

  auto upperBound = A.end();
  auto lowerBound = A.end();
  
  upperBound = std::upper_bound(minimumValueOverZero, A.end(), 0);
  lowerBound = std::lower_bound(minimumValueOverZero, A.end(), 0);

  if (*upperBound > 1) return 1;

  do
  {
    if (*lowerBound + 2 == *upperBound) {
      return searchElement + 1;
    }
    ++searchElement;

    upperBound = std::upper_bound(minimumValueOverZero, A.end(), searchElement);
    lowerBound = std::lower_bound(minimumValueOverZero, A.end(), searchElement);
  }
  while (searchElement < A.back());

  return searchElement + 1;
}



int main()
{


  std::vector<int>  M = { -1 , -3 , -399, 5, 7 ,10, 0 };
  std::cout << "M:" << solution(M) << " M:" << binarySolution(M) << std::endl;

  

  std::vector<int>  L = { 2 };
  std::cout << "L" << solution(L) << " L:" << binarySolution(L) << std::endl;

  std::vector<int>  G = { 1, 2, 3 };
  std::cout << "G" << solution(G) << " G:" << binarySolution(G) << std::endl;

  std::vector<int>  A = { 1, 3, 6, 4, 1, 2 };
  std::cout << "A" << solution(A) << " A:" << binarySolution(A) << std::endl;

  std::vector<int>  B = { -1 , -3 };
  std::cout << "B" << solution(B) << " B:" << binarySolution(B) << std::endl;

  std::vector<int>  C = { 1, 3, 6, 4, 1, 200 };
  std::cout << "C" << solution(C) << " C:" << binarySolution(C) << std::endl;

  std::vector<int>  D = { 1, 3, 6, 4, 1, 2 };
  std::cout << "D" << solution(D) << " D:" << binarySolution(D) << std::endl;

  std::vector<int>  X = { 1000001, 3, 6, 4, 1, -1000001 };
  std::cout << "X" << solution(X) << " X:" << binarySolution(X) << std::endl;
    
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
