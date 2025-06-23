#include "Words.h"
#include <string>

using namespace std;

int Words::freq(string str) {
  int count = 0;
  for (const string& word : words_) {
    size_t pos = 0;
    while ((pos = word.find(str, pos)) != string::npos) {
      count++;
      pos += str.length();
    }
  }
  return count;
}

int Words::freqE(string str) {
  int count = 0;
  for (const string& word : words_) {
    size_t pos = 0;
    while ((pos = word.find(str, pos)) != string::npos) {
      if (pos + str.length() == word.length()) {
        count++;
        break;
      }
      pos += str.length();
    }
  }
  return count;
}
