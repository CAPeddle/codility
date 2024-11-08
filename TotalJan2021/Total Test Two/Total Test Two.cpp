// Total Test Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>


#define TASK2

int solution(std::vector<std::string>& T, std::vector<std::string>& R) {
  // write your code in C++14 (g++ 6.2.0)

  std::unordered_map<std::string, bool > groupTests;

  // for (auto cs : T)
  for (size_t i = 0; i < T.size(); ++i)
  {
    auto testName = T.at(i);
    bool testPassed = true;

    const auto found = testName.find_first_of("0123456789");  //should be isdigit
    auto groupName = testName.substr(0, found+1);
    if (R.at(i) != "OK") testPassed = false;

    auto groupInsert = groupTests.insert(std::make_pair(groupName, testPassed));
    if (!groupInsert.second)
    {
      //add element
      if (groupInsert.first->second == true && testPassed == false)
        groupInsert.first->second = false;
    }
  }

  auto passedTests = 0;
  for (const auto groupTest : groupTests)
  {
    if (groupTest.second) ++passedTests;
  }

  const auto total = div(passedTests * 100 , groupTests.size());

  return total.quot;
}



int solution(std::vector<int>& A) {
  // write your code in C++14 (g++ 6.2.0)

  //zero based so 
  std::unordered_map<int,int> locationsVisits;

  for (auto location : A)
  {
    locationsVisits.insert(std::make_pair(location, 0));
  }

  auto visited = [&](int location)
  {
    const auto locationHasBeenVisited = locationsVisits.insert(std::make_pair(location,1));
    if (!locationHasBeenVisited.second)
    {
      locationHasBeenVisited.first->second++;
    }

    return;
  };

  //

  auto start = A.begin();
  auto end = start + 1;

  while (start != end)
  {    
    std::for_each(start, end, visited);
    
    auto notAllVisited = std::find_if(std::begin(locationsVisits), std::end(locationsVisits), [](std::pair<int, int> location) {return location.second == 0; });

    ++end;

    locationsVisits.clear();
};

  return std::distance(start, end);
  

  //brute force loop from the start to the end decrementing the start stopping when all locations visited
  //so need to populate the map with all the locations first

  //
  // // auto notAllVisited = std::find_if(std::begin(locationsVisits), std::end(locationsVisits), visited);
  //
  // auto maxVisited = [=]() {
  //   auto maxVisit = 0;
  //   for (const auto locationsVisit : locationsVisits)
  //   {
  //     maxVisit = std::max(maxVisit, locationsVisit.second);
  //   }
  //   return maxVisit;
  // };
  //
  //
  //
  // while (start != end)
  // {
  //   auto allVisited = std::find_if(start, end, visited);
  //     
  // }

}


int solution(std::vector<int>& A, int S) {
  // write your code in C++14 (g++ 6.2.0)

  auto start = A.begin();
  auto end = start + 1;

  auto equalsTarget = 0;

  if (A.front() == S) ++equalsTarget;
  if (A.back() == S) ++equalsTarget;
  do
  {
    auto sum = std::accumulate(start, end, 0);
    auto entries = std::distance(start, end);
    if ( sum / entries == S) ++equalsTarget;

    if (start == A.begin())
    {
      ++end;
    }
    if (end == A.end())
    {
      ++start;
    }

  }   while (start != end);

  return equalsTarget;
}

int main()
{

  //TASK1
  {
    std::vector<std::string> T{ "test1a", "test2", "test1b", "test1c","test3" };
    std::vector<std::string> R{ "Wrong Answer", "OK", "Runtime error", "OK","Time limit exceeded" };

    std::vector<std::string> T2{ "codility1", "codility3", "codility2", "codility4b","codility4a" };
    std::vector<std::string> R2{ "Wrong Answer", "OK", "OK", "Runtime error", "OK"};

    solution(T, R);
  }

  //TASK2
  {
    std::vector<int> A{ 7,3,7,3,1,3,4,1 };
    solution(A);    
  }

  //TASK3
  {
    std::vector<int> A{ 2,1,3 };
    int average = 2;
    solution(A,average);    
  }


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
