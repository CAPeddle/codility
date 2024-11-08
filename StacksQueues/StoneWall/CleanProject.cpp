// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <stack>
#include <vector>

int solution(const std::vector<int> &H) {
  std::stack<int> stack;
  int stones = 0;
  for (auto height : H) {
    while (!stack.empty() && stack.top() > height) {
      stack.pop();
    }
    if (!stack.empty() && stack.top() == height) {
      continue;
    }
    stones++;
    stack.push(height);
  }
  return stones;
}