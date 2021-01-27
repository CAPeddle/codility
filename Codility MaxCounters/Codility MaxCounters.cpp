// Codility MaxCounters.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

void printCounters(const std::vector<int>& A)
{
  for (auto a : A)
  {
    std::cout << a;
  }
  std::cout << std::endl;
}
#define FILL

std::vector<int> solution(int N, std::vector<int>& A) {
  std::vector<int> counters(N);

  for (auto a : A)
  {
    if (a >= 1 && a <= N)
    {
      ++counters[a-1];
    }else
    {
      auto maxCounter = std::max_element(counters.begin(), counters.end());
#ifdef FILL
      std::fill(counters.begin(), counters.end(), *maxCounter);
#else
      std::vector<int> second(N, *maxCounter);
      counters.swap(second);
#endif
    }
  }
  return counters;
}

int main()
{

  std::vector<int>  G = { 3, 4, 4, 6, 2122 , 4, 4 };

  long long total(0);
  for (int i = 0; i < 20; ++i)
  {
    auto start = std::chrono::system_clock::now();
    auto result = solution(2120, G);
    auto stop = std::chrono::system_clock::now();
    const auto timeRun = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    std::cout << "\n" << timeRun << " µs";
    total += timeRun;
  }
  std::cout << "\n\n" << total / 20 << " µs";

  // printCounters(result);
  
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
