#include "CleanProject.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief Generates a bitmask based on the order of characters in the
 * fullCharset.
 *
 * This function takes a string S and a fullCharset string, and generates a
 * bitmask where each bit represents the presence of a character from the
 * fullCharset in the string S. The position of the bit corresponds to the
 * position of the character in the fullCharset.
 *
 * @param S The input string for which the bitmask is to be generated.
 * @param fullCharset The string containing the full set of characters in a
 * specific order.
 * @return A bitmask representing the presence of characters from fullCharset in
 * the string S.
 */
unsigned int LetterSequenceBasedBitmaskOf(const std::string &S,
                                  const std::string fullCharset) {
  unsigned int result = 0;

  for (char c : S) {
    size_t findPosition = fullCharset.find(c);
    if (findPosition == std::string::npos) {
      throw std::invalid_argument("Character " + std::string(1, c) +
                                  " not found in fullCharset " + fullCharset +
                                  " for string " + S);
    }

    size_t bitFlag = 0;
    bitFlag |= (1 << (fullCharset.size() - 1 - findPosition));
    result |= bitFlag;
  }

  return result;
}

bool HasAtmostBitsSet(unsigned int num, unsigned int maxBits) {
  unsigned int count = 0;
  while (num > 0) {
    if (num & 1) {
      count++;
    }
    if (count >= maxBits + 1) {
      return false;
    }
    num >>= 1;
  }
  return true;
}

std::vector<std::string> removeDuplicateLetters(
    const std::vector<std::string> &input) {
  std::vector<std::string> result;

  for (const auto &str : input) {
    std::unordered_set<char> seen;
    std::string uniqueStr;

    for (char c : str) {
      if (seen.find(c) == seen.end()) {
        seen.insert(c);
        uniqueStr += c;
      }
    }

    result.push_back(uniqueStr);
  }

  return result;
}

std::string getSortedLetterFrequency(const std::vector<std::string> &strings) {
  std::unordered_map<char, int> letterCount;

  // Count the frequency of each letter
  for (const auto &str : strings) {
    for (char c : str) {
      letterCount[c]++;
    }
  }

  // Create a vector of pairs (frequency, letter) for sorting
  std::vector<std::pair<int, char>> freqList;
  for (const auto &entry : letterCount) {
    freqList.push_back({entry.second, entry.first});
  }

  // Sort the vector by frequency in descending order, and by letter in
  // ascending order if frequencies are equal
  std::sort(freqList.begin(), freqList.end(),
            [](const std::pair<int, char> &a, const std::pair<int, char> &b) {
              if (a.first == b.first) {
                return a.second < b.second;
              }
              return a.first > b.first;
            });

  // Create the result string
  std::string result;
  for (const auto &entry : freqList) {
    result += entry.second;
  }

  return result;
}

int solution(vector<string> &S, int K) {
  // description says this can be assumed to not be possible
  // still feels wrong to not have this check
  if (K == 0) return 0;

  auto uniqueStrings = removeDuplicateLetters(S);
  auto fullCharset = getSortedLetterFrequency(uniqueStrings);
  unsigned int maxLetters = LetterSequenceBasedBitmaskOf(fullCharset, fullCharset);

  auto result = 0;
  for (unsigned int i = 0; i <= maxLetters; ++i) {
    if (!HasAtmostBitsSet(i, K)) {
      continue;
    }
    auto buildable = 0;
    for (const auto &str : uniqueStrings) {
      unsigned int bitmask = LetterSequenceBasedBitmaskOf(str, fullCharset);
      if ((bitmask & i) == bitmask) {
        buildable++;
      }
    }
    result = std::max(result, buildable);
  }

  return result;
}
