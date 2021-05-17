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

#define TASK3

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

#ifdef TASK3

int MonthToInt(const std::string& month)
{
  if (month == "January") {    return 1;  }
  if (month == "February ") {    return 2;  }
  if (month == "March") {    return 3;  }
  if (month == "April") {    return 4;  }
  if (month == "May") {    return 5;  }
  if (month == "June") {    return 6;  }
  if (month == "July") {    return 7;  }
  if (month == "August") {    return 8;  }
  if (month == "September") {    return 9; }
  if (month == "October") {    return 10;  }
  if (month == "November ") {    return 11;  }
  if (month == "December ") {    return 12;  }
  return -1;
}

int DayToInt (const std::string& day)
{
  if (day == "Monday") return 1;
  if (day == "Tuesday") return 2;
  if (day == "Wednesday") return 3;
  if (day == "Thursday") return 4;
  if (day == "Friday") return 5;
  if (day == "Saturday") return 6;
  if (day == "Sunday") return 7;
  return 0;
}

std::string IntToDay (const int& day)
{
  switch (day)
  {
  case 1: return "Monday";
  case 2: return "Tuesday";
  case 3: return "Wednesday";
  case 4: return "Thursday";
  case 5: return "Friday";
  case 6: return "Saturday";
  case 7: 
  case 0: return "Sunday";
  }
  return "";
}

int MonthDays(const int& _y, const int& _month)
{
  //for feb
  if (_month == 2)
  {
    if ((_y % 400 == 0) || (_y % 4 == 0 && _y % 100 != 0))
      return 29;
    
    return 28;
  }
  //for months which has 31 days
  if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
    return 31;
  
  return 30;
}

int task3(int Y, std::string& A, std::string& B, std::string& W) {
  //Y - Year of vacation
  //A - Month Vacation starts
  //B - Month Vacation Ends
  //W - First day of year

  const auto& endMonth(MonthToInt(B));
  const auto& FirstDayOfYear(DayToInt(W));

  const auto startMonth = MonthToInt(A);

  int daysTillStartMonth = 0;

  for (auto month = 1; month < startMonth; ++month)
  {
    daysTillStartMonth += MonthDays(Y, month);
  }

  std::cout << "daysTillStartMonth:" << daysTillStartMonth << "\n";

  const auto monthStartDivResult = div(daysTillStartMonth, 7);

  auto StartMonthFirstDay = (FirstDayOfYear + monthStartDivResult.rem) % 7;
  if (StartMonthFirstDay == 0) StartMonthFirstDay = 7;

  std::cout << A << " starts on " << IntToDay(StartMonthFirstDay) << "\n";

  int daysTillEndOfEndMonth = 0;

  for (auto month = startMonth; month <= endMonth; ++month)
  {
    daysTillEndOfEndMonth += MonthDays(Y, month);
  }

  const auto monthEndDivResult = div(daysTillEndOfEndMonth, 7);

  auto roundedUpWeeks = static_cast<int>(ceil(daysTillEndOfEndMonth/ 7.0));

  auto EndMonthLastDay = (((StartMonthFirstDay) + monthEndDivResult.rem) % 7) - 1;
  if (EndMonthLastDay == 0) EndMonthLastDay = 7;  
  if (EndMonthLastDay == -1) EndMonthLastDay = 6;

  std::cout << "Month after " << B << " starts on " << IntToDay(EndMonthLastDay) << "\n";

  //Round up daysTillEndOfEndMonth and subtract if start of first month isn't Monday
  //similarly if month end isn't on Sunday subtract a week

  if (StartMonthFirstDay != 1) --roundedUpWeeks;
  if (EndMonthLastDay != 7) --roundedUpWeeks;

  return roundedUpWeeks;  
}
#endif


int main()
{
#ifdef TASK1
  std::vector<std::string> A{"pim","pom"};
  std::vector<std::string> B{"999999999", "777888999"};
  std::string P("88999");

  std::cout << task1(A, B, P);

  A = { "sander", "amy", "ann", "michael"};
  B = { "123456789", "234567890", "789123456", "123123123" };
  P = "1";

  std::cout << task1(A,B,P);

#endif

#ifdef TASK2
    std::string number1("00-44  48 5555 8361");  
    std::string number2("0 - 22 1985--324");
    std::string number3("00 - 44  48 5555 8361");
    std::cout << task2(number1);
#endif

#ifdef TASK3

  int Y = 2014; 
  std::string A("April");
  std::string B("May");
  std::string W("Wednesday");

  std::cout << task3(Y,A,B,W);

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
