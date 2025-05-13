
// Frog Jump.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

#include <iostream>

int solution(int X, int Y, int D) {
  // write your code in C++14 (g++ 6.2.0)
  const div_t divResult = div(Y - X, D);
  if (divResult.rem > 0) return divResult.quot + 1;
  return divResult.quot;
}


int main()
{
    std::cout << solution(1, 2, 30) << "\n";
    std::cout << solution(10, 85, 30) << "\n";
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
