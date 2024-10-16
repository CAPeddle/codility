// OddOccurrencesInArray.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

void printVector(const std::vector<int>& A) {
  for (auto a : A) {
    std::cout << a;
  }
  std::cout << std::endl;
}

void printVector(const std::vector<int>::iterator& _start,
                 const std::vector<int>::iterator& _end) {
  for (auto it = _start; it != _end; ++it) {
    std::cout << *it;
  }
  std::cout << std::endl;
}

/*
int threadSolution(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)

  std::sort(A.begin(), A.end());

  // vector container stores threads
  std::vector<std::thread> workers;
  for (int i = 0; i < 5; i++) {

    workers.emplace_back([i](const std::vector<int>::iterator& _start, const
std::vector<int>::iterator& _end)
      {
        printVector(_start, _end);
        std::cout << "thread function " << i << "\n";
      });
  }
  std::cout << "main thread\n";

  // Looping every thread via for_each
  // The 3rd argument assigns a task
  // It tells the compiler we're using lambda ([])
  // The lambda function takes its argument as a reference to a thread, t
  // Then, joins one by one, and this works like barrier
  std::for_each(workers.begin(), workers.end(), [](std::thread& t)
    {
      t.join();
    });

  return 0;

}
*/
int solution(std::vector<int>& A) {
  int res = 0;
  for (auto i : A) {
    res ^= i;
  }
  return res;
}
