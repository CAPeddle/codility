// Total Codility Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include <algorithm> 
#include <string>
#include <cctype>
#include <locale>
#include <sstream>
#include <vector>


std::string task1(std::vector<std::string>& A, std::vector<std::string>& B, std::string& P) {
  const auto hits = std::count_if(std::begin(B), std::end(B), [P](const std::string& _number)
  {
    return _number.find(P) != std::string::npos;
  });

  if (hits == 0) return "NO CONTACT";

  std::vector<std::string> options;
  auto result3 = std::begin(B);
  for (int i = 0; i < hits; ++i)
  {
    result3 = std::find_if(result3, std::end(B), [P](const std::string& _number)
    {
      return _number.find(P) != std::string::npos;
    });

    const auto position = result3 - B.begin();
    options.push_back(A.at(position));
    ++result3;
  }
  
  std::sort(options.begin(), options.end());

  return *options.begin();
}

std::string task2(std::string& S) {
  // write your code in C++14 (g++ 6.2.0)

  S.erase(std::remove_if(S.begin(), S.end(),
    [](unsigned char x) {return !std::isdigit(x); }),
    S.end());

  const auto divResult = div(S.length(), 3);
  size_t groups = divResult.quot;
  if (divResult.rem == 1)
    --groups;

  std::stringstream outputStream;
  size_t letters(0);
  size_t groupSize(2);
  size_t noGroups(0);
  for (auto s : S)
  {
    outputStream << s;
    ++letters;
    if (letters > groupSize) {
      outputStream << "-";
      letters = 0;
      ++noGroups;
    }

    if (noGroups == groups && groupSize == 2) {
      --groupSize;
    }
  }
  std::string outputResult(outputStream.str());
  if (outputResult.back() == '-') outputResult.pop_back();
  return outputResult;
}

int task3(int Y, std::string& A, std::string& B, std::string& W) {
  // write your code in C++14 (g++ 6.2.0)

  auto y = [](const std::string& _month)
  {
    if (_month == "January") return 1;
    if (_month == "Feburuary") return 1;
    if (_month == "January") return 1;
    if (_month == "January") return 1;
    if (_month == "January") return 1;
    if (_month == "January") return 1;
    if (_month == "January") return 1;
    if (_month == "January") return 1;

  };

  //given april (4th month)
  //januaruu

  int GetFirstMonday (int year, std::string month)
  {
    
  }

  std::string StartMonth(A);
  std::string EndMonth(B);
  std::string FirstDayOfYear(W);

  int startMonth(0);
  int endMonth(0);
  if ()
}

#define TASK3

int main()
{

#ifdef TASK3

  int Y = 2014; 
  std::string A;
  std::string B;
  std::string W;

  std::cout << task3(number3);

#endif

#ifdef TASK1
  std::vector<std::string> A{"pim","pom"};
  std::vector<std::string> B{"999999999", "777888999"};
  std::string P("88999");

  A = { "sander", "amy", "ann", "michael"};
  B = { "123456789", "234567890", "789123456", "123123123" };
  P = "1";

  std::cout << task1(A,B,P);


#endif


#ifdef TASK2
    std::string number1("00-44  48 5555 8361");  
    std::string number2("0 - 22 1985--324");
    std::string number3("00 - 44  48 5555 8361");
    std::cout << task2(number3);
#endif

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
