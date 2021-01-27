// OddOccurrencesInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>


void printVector(const std::vector<int>& A)
{
  for (auto a : A)
  {
    std::cout << a;
  }
  std::cout << std::endl;
}


void printVector(const std::vector<int>::iterator& _start, const std::vector<int>::iterator& _end)
{
  for (auto it = _start; it != _end; ++it)
  {
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

    workers.emplace_back([i](const std::vector<int>::iterator& _start, const std::vector<int>::iterator& _end)
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
  // write your code in C++14 (g++ 6.2.0)
  if (A.size() == 1) return A.front();

  std::sort(A.begin(), A.end());

  for (size_t i = 0; i <= A.size(); ++(++i))
  {

    if (i == A.size() - 1) return A.back();
    if (A.at(i) != A.at(i + 1)) return A.at(i);
       
  }

  return A.back();

}

int main()
{
  std::vector<int> A{ 9,3,9,3,9,9,7 };
  printVector(A);
  std::cout << solution(A) << "\n";

  std::vector<int> B{ 9,3,9,3,9,9,11 };
  printVector(B);
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
