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
uint LetterSequenceBasedBitmaskOf(const std::string &S,
                                  const std::string fullCharset) {
  uint result = 0;

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

bool HasAtmostBitsSet(uint num, uint maxBits) {
  int count = 0;
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

  auto uniqueStrings = removeDuplicateLetters(strings);

  // Count the frequency of each letter
  for (const auto &str : uniqueStrings) {
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

int NumBuildable(const std::vector<std::string> &A, std::string S) {
  int result = 0;

  auto uniqueStrings = removeDuplicateLetters(A);
  auto fullCharset = getSortedLetterFrequency(uniqueStrings);

  // Strip letters from S that do not appear in the fullCharset
  std::string filteredS;
  for (char c : S) {
    if (fullCharset.find(c) != std::string::npos) {
      filteredS += c;
    }
  }
  S = filteredS;
  if (S.empty()) {
    return 0;
  }

  std::vector<int> bitmasks;
  for (const std::string &str : A) {
    bitmasks.push_back(LetterSequenceBasedBitmaskOf(str, fullCharset));
  }

  uint SBitmask = LetterSequenceBasedBitmaskOf(S, fullCharset);

  for (int bitmask : bitmasks) {
    if ((bitmask & SBitmask) == bitmask) {
      result++;
    }
  }
  return result;
}

int solution(vector<string> &S, int K) {
  // description says this can be assumed to not be possible
  // still feels wrong to not have this check
  if (K == 0) return 0;

  auto uniqueStrings = removeDuplicateLetters(S);
  auto fullCharset = getSortedLetterFrequency(uniqueStrings);
  uint maxLetters = LetterSequenceBasedBitmaskOf(fullCharset, fullCharset);

  auto result = 0;
  for (uint i = 0; i <= maxLetters; ++i) {
    if (!HasAtmostBitsSet(i, K)) {
      continue;
    }
    auto buildable = 0;
    for (const auto &str : uniqueStrings) {
      uint bitmask = LetterSequenceBasedBitmaskOf(str, fullCharset);
      if ((bitmask & i) == bitmask) {
        buildable++;
      }
    }
    result = std::max(result, buildable);
  }

  return result;
}

int solution_phind(std::vector<std::string> &S, int K) {
  // Create a set of all unique characters
  std::unordered_set<char> chars;
  for (const auto &str : S) {
    for (char c : str) {
      chars.insert(c);
    }
  }

  // Convert the set to a vector and sort it
  std::vector<char> sorted_chars(chars.begin(), chars.end());
  std::sort(sorted_chars.begin(), sorted_chars.end());

  int max_strings = 0;

  for (int i = 0; i < sorted_chars.size(); ++i) {
    int current_char = sorted_chars[i];

    // Count occurrences of the current character
    int count = 0;
    for (const auto &str : S) {
      size_t pos = str.find(current_char);
      while (pos != std::string::npos) {
        count++;
        pos = str.find(current_char, pos + 1);
      }
    }

    // Check if adding this character increases the count of strings
    int new_count = max_strings;
    for (int j = 0; j < i; ++j) {
      new_count += count;
    }

    // Update max_strings if necessary
    max_strings = std::max(max_strings, new_count);

    // If K characters are chosen, break the loop
    if (i == K - 1) break;
  }

  return max_strings;
}

int solution_bitmask(vector<string> &S, int K) {
  // description says this can be assumed to not be possible
  // still feels wrong to not have this check
  if (K == 0) return 0;

  vector<string> uniqueCharStrings;
  for (const string &str : S) {
    unordered_set<char> uniqueChars(str.begin(), str.end());
    if (uniqueChars.size() <= K) {
      string uniqueStr(uniqueChars.begin(), uniqueChars.end());
      uniqueCharStrings.push_back(uniqueStr);
    }
  }

  vector<int> bitmasks;
  vector<string> filteredStrings;

  // Step 1: Convert strings to bitmasks and filter strings
  for (const string &str : uniqueCharStrings) {
    int bitmask = 0;
    unordered_set<char> uniqueChars;
    for (char c : str) {
      bitmask |= (1 << (c - 'a'));
      uniqueChars.insert(c);
    }
    if (uniqueChars.size() <= K) {
      bitmasks.push_back(bitmask);
      filteredStrings.push_back(str);
    }
  }

  // Step 2: Count frequency of each letter in filtered strings
  unordered_map<char, int> letterFreq;
  for (const string &str : filteredStrings) {
    for (char c : str) {
      letterFreq[c]++;
    }
  }

  // Step 3: Select top K letters
  vector<pair<int, char>> freqList;
  for (const auto &entry : letterFreq) {
    freqList.push_back({entry.second, entry.first});
  }
  sort(freqList.rbegin(), freqList.rend());

  int selectedBitmask = 0;
  for (int i = 0; i < min(K, (int)freqList.size()); ++i) {
    selectedBitmask |= (1 << (freqList[i].second - 'a'));
  }

  // Step 4: Count buildable strings
  int buildableCount = 0;
  for (int bitmask : bitmasks) {
    if ((bitmask & selectedBitmask) == bitmask) {
      buildableCount++;
    }
  }

  return buildableCount;
}

int solution_freq(vector<string> &S, int K) {
  // description says this can be assumed to not be possible
  // still feels wrong to not have this check
  if (K == 0) return 0;

  vector<string> uniqueCharStrings;
  for (const string &str : S) {
    unordered_set<char> uniqueChars(str.begin(), str.end());
    if (uniqueChars.size() <= K) {
      string uniqueStr(uniqueChars.begin(), uniqueChars.end());
      uniqueCharStrings.push_back(uniqueStr);
    }
  }

  vector<unordered_map<char, int>> freqMaps;
  vector<string> filteredStrings;

  // Step 1: Create frequency maps and filter strings
  for (const string &str : uniqueCharStrings) {
    unordered_map<char, int> freqMap;
    unordered_set<char> uniqueChars;
    for (char c : str) {
      freqMap[c]++;
      uniqueChars.insert(c);
    }
    if (uniqueChars.size() <= K) {
      freqMaps.push_back(freqMap);
      filteredStrings.push_back(str);
    }
  }

  // Step 2: Count frequency of each letter in filtered strings
  unordered_map<char, int> letterFreq;
  for (const auto &freqMap : freqMaps) {
    for (const auto &entry : freqMap) {
      letterFreq[entry.first]++;
    }
  }

  // Step 3: Select top K letters
  vector<pair<int, char>> freqList;
  for (const auto &entry : letterFreq) {
    freqList.push_back({entry.second, entry.first});
  }
  sort(freqList.rbegin(), freqList.rend());

  unordered_set<char> selectedLetters;
  for (int i = 0; i < min(K, (int)freqList.size()); ++i) {
    selectedLetters.insert(freqList[i].second);
  }

  // Step 4: Count buildable strings
  int buildableCount = 0;
  for (const string &str : filteredStrings) {
    bool canBuild = true;
    for (char c : str) {
      if (selectedLetters.find(c) == selectedLetters.end()) {
        canBuild = false;
        break;
      }
    }
    if (canBuild) {
      buildableCount++;
    }
  }

  return buildableCount;
}
