#include "gtest/gtest.h"
// test.cpp
#include <string>
#include <vector>

#include "CleanProject.h"

using namespace std;

TEST(SolutionTest, BasicCases) {
  vector<string> S1 = {"abc", "abb", "cb", "a", "bbb"};
  EXPECT_EQ(solution(S1, 2), 3);

  vector<string> S2 = {"adf", "jjbh", "jcgj", "eijj", "adf"};
  EXPECT_EQ(solution(S2, 3), 2);

  vector<string> S3 = {"abcd", "efgh"};
  EXPECT_EQ(solution(S3, 3), 0);

  vector<string> S4 = {"bc", "edf", "fde", "dge", "abcd"};
  EXPECT_EQ(solution(S4, 4), 3);
}

TEST(SolutionTest, EdgeCases) {
  vector<string> S5 = {};
  EXPECT_EQ(solution(S5, 2), 0);

  vector<string> S6 = {"a", "b", "c"};
  EXPECT_EQ(solution(S6, 0), 0);

  vector<string> S7 = {"a", "b", "c"};
  EXPECT_EQ(solution(S7, 3), 3);

  vector<string> S8 = {"a", "aa", "aaa"};
  EXPECT_EQ(solution(S8, 1), 3);

  vector<string> S9 = {"abcdefghij", "abcdefghij", "abcdefghij"};
  EXPECT_EQ(solution(S9, 10), 3);
}

/*

You are given an array S made of N strings and an integer K.
Choose at most K letters from the alphabet that will allow you to build as many
strings from array S as possible. Any of the chosen letters can be used multiple
times when building the strings. What is the maximum number of strings from S
that can be built? Write a function: int solution (vector<string> &S, int K);
that, given an array S and an integer K, returns the maximum number of strings
from S that can be built. Examples:

Given S = ["abc", "abb", "cb", "a", "bbb"] and K = 2, the function should
return 3. Strings "abb", "a" and "bbb" can be built using the two letters 'a'
and 'b'.

Given S = ["adf", "jjbh", "jcgj", "eijj", "adf"] and K = 3, the function should
return 2. Two strings "adf" can be built using three letters 'a', 'd' and 'f'.

Given S = ["abcd", "efgh"] and K = 3, the function should return O. It is not
possible to build any string from S using at most three letters.

Given S = ["bc", "edf", "fde", "dge", "abcd"] and K = 4, the function should
return 3. Strings "edf", "fde" and "dge" can be built using the four letters
'd', 'e', 'f' and 'g'.

Write an efficient algorithm for the following assumptions:
• N is an integer within the range [1..50,000];
• K is an integer within the range [1..10];
• each string in S has a length within the range [1..15];
• each string in S is made from only the first ten lowercase letters of the
alphabet ('a'-'j').

*/