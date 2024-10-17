// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K) {
  std::vector<int> result;

  return result;
}

// https://molchevskyi.medium.com/best-solutions-for-codility-lessons-lesson-5-prefix-sums-68b716f9d825
std::vector<int> DNA_impact(const std::string &s, std::vector<int> &p,
                            std::vector<int> &q) {
  enum impact_t { A = 1, C = 2, G = 3, T = 4 };
  struct counters_t {
    int A = 0;
    int C = 0;
    int G = 0;
  };
  size_t dna_len = s.length();
  size_t p_size = p.size();
  std::vector<int> result(p_size, 0);
  std::vector<counters_t> cumulative_sums;
  cumulative_sums.reserve(dna_len + 1);
  counters_t counters = counters_t();
  for (size_t i = 0; i <= dna_len; ++i) {
    cumulative_sums.push_back(counters);
    switch (s[i]) {
      case 'A': {
        counters.A++;
        break;
      }
      case 'C': {
        counters.C++;
        break;
      }
      case 'G': {
        counters.G++;
        break;
      }
    }
  }
  for (size_t i = 0; i < p_size; ++i) {
    int from = p[i], to = q[i] + 1;
    // If the number of A is increased throughout
    // the query the it contains A
    if (cumulative_sums[to].A - cumulative_sums[from].A > 0) {
      result[i] = impact_t::A;
    }
    // the same for C and other nucleotides with higher
    // impact factor
    else if (cumulative_sums[to].C - cumulative_sums[from].C > 0) {
      result[i] = impact_t::C;
    } else if (cumulative_sums[to].G - cumulative_sums[from].G > 0) {
      result[i] = impact_t::G;
    } else {  // one of the counters must be changed, so it is the T
      result[i] = impact_t::T;
    }
  }
  return result;
}