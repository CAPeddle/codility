#include "gtest/gtest.h"

// Demonstrate some basic assertions.
TEST(AltenProb2, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// test.cpp
#include "CleanProject.h"
// #include "pch.h"

TEST(AltenProb2, TestCleanProject_TestSol_Test1) {
  std::string S("abacdec");
  auto actual = solution(S);
  auto expected = 3;
  EXPECT_EQ(actual, expected);

  S = "world";
  actual = solution(S);
  expected = 1;
  EXPECT_EQ(actual, expected);

  S = "dddd";
  actual = solution(S);
  expected = 4;
  EXPECT_EQ(actual, expected);

  S = "cycle";
  actual = solution(S);
  expected = 2;
  EXPECT_EQ(actual, expected);

  S = "abba";
  actual = solution(S);
  expected = 2;
  EXPECT_EQ(actual, expected);
}

/*

You are given a string consisting of lowercase letters of the English alphabet.
You must split this string into a minimal number of substrings in such a way
that no letter occurs more than once in each substring. For example, here are
some correct splits of the string "abacdec": ('a', 'bac', 'dec'), ('a', bacd',
'ec') and ('ab', 'ac', 'dec'). Write a function: int solution(string &S); that,
given a string S of length N, returns the minimum number of substrings into
which the string has to be split. Examples:

Given 'world', your function should return 1. There is no need to split the
string into substrings as all letters occur just once. Given 'dddd', your
function should return 4. The result can be achieved by splitting the string
into four substrings ('d', 'd', 'd', 'd'). Given 'cycle', your function should
return 2. The result can be achieved by splitting the string into two substrings
('cy', 'cle') or ('c', 'ycle'). Given 'abba', your function should return 2. The
result can be achieved by splitting the string into two substrings ('ab', 'ba').

Write an efficient algorithm for the following assumptions:
• N is an integer within the range [1..1,000,000];
⚫ string S is made only of lowercase letters (a-z).

*/