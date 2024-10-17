// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
/*
int solution(vector<string> &S, int K) {
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
*/

int solution(vector<string> &S, int K) {
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

  // Find the longest unique character string
  string longestUniqueStr;
  for (const string &str : uniqueCharStrings) {
    if (str.size() > longestUniqueStr.size()) {
      longestUniqueStr = str;
    }
  }

  // Check which unique character strings are in the set of the longest string
  unordered_set<char> longestUniqueSet(longestUniqueStr.begin(),
                                       longestUniqueStr.end());
  vector<string> validUniqueCharStrings;
  for (const string &str : uniqueCharStrings) {
    bool isValid = true;
    for (char c : str) {
      if (longestUniqueSet.find(c) == longestUniqueSet.end()) {
        isValid = false;
        break;
      }
    }
    if (isValid) {
      validUniqueCharStrings.push_back(str);
    }
  }
  // Calculate the number of subsets of the longest unique character string
  int numSubsets = 1 << validUniqueCharStrings.size();

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
