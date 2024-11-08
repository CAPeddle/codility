// GenomicRange.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "../Total Codility Test/AuxiliaryFunctions.h"


int impactFactor (char nucleotide)
{
  switch (nucleotide)
  {
  case 'A': return 1;
  case 'C': return 2;
  case 'G': return 3;
  case 'T': return 4;
  default: return 100; //Because the test is for the lowest impact
  }
}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q)
{

  vector<pair<char, int> > vp;
  vp.reserve(S.size());
  
  // Inserting element in pair vector
  // to keep track of previous indexes
  for (size_t i = 0; i < S.size(); ++i) {
    vp.emplace_back(S.at(i), i);
  }

  std::sort(vp.begin(), vp.end());

  vector<int> solution;
  for (size_t i = 0; i < P.size(); ++i)
  {        
    size_t y = 0;
    auto letterImpact = impactFactor(vp.at(y).first);
    while (y < S.size() && letterImpact <= impactFactor('T'))
    {
      letterImpact = impactFactor(vp.at(y).first);
      const auto letterImpactIndex = vp.at(y).second;
      const auto impactRangeStart = P.at(i);
      const auto impactRangeEnd = Q.at(i);

      if (letterImpactIndex >= impactRangeStart && letterImpactIndex <= impactRangeEnd)
      {
        solution.push_back(letterImpact);

        break;
      }
      ++y;
    }
  }
  return solution;
}

int main()
{
    {
    std::string S = "CAGCCTA";

    vector<int> P{ 2,5,0 };
    vector<int> Q{ 4,5,6 };

    printVector(solution(S, P, Q));
    std::cout << "\n";
  }

  {
    std::string S = "T";

      vector<int> P{ 0 };
      vector<int> Q{ 0 };

      printVector(solution(S, P, Q));
      std::cout << "\n";
  }
}

/*

A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence.
Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively.
You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters.
There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers.
The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

The answers to these M = 3 queries are as follows:

        The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
        The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
        The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function:

    vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        M is an integer within the range [1..50,000];
        each element of arrays P, Q is an integer within the range [0..N − 1];
        P[K] ≤ Q[K], where 0 ≤ K < M;
        string S consists only of upper-case English letters A, C, G, T.

Copyright 2009–2021 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/