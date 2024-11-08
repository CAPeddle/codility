// Codility BinaryGap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

int solution(int N) {
  // write your code in C++14 (g++ 6.2.0)

  auto remainder = 0;
  auto quotient = N;
  auto startCounting(false);
  auto maxBinaryGapLength(0);
  auto binaryGapLength(0);

  remainder = N %  2;
  quotient = N / 2;
  if (remainder == 1) startCounting = true;

  std::cout << remainder << "\n";

  do 
  {
    remainder = quotient % 2;
    quotient = quotient / 2;

    if (startCounting && remainder == 0) ++binaryGapLength;

    if (remainder == 1 && startCounting)
    {
      maxBinaryGapLength = std::max(maxBinaryGapLength, binaryGapLength);
      binaryGapLength = 0;
    }
    if (remainder == 1) startCounting = true;

    std::cout << remainder << "\n";
  } while (quotient > 0);


  return maxBinaryGapLength;
}

int main()
{
  int L(561892);
  std::cout << " maxBinaryGapLength " << solution(L) << std::endl;
  
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
