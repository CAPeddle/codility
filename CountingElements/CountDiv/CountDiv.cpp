// CountDiv.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
//

#include <iostream>

int solution(int a, int b, int k)
{
  if (a % k > 0)
    a += k - (a % k);

  return b / k - a / k + 1; // include a/k
}

int main()
{
  int A = 6;
  int B = 11;
  int K = 2;

  std::cout << solution(A, B, K) << "\n";

  A = 7;
  B = 12;
  K = 2;
  std::cout << solution(A,B,K) << "\n";


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
