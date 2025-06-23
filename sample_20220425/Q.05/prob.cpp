#include "Words.h"
#include <iostream>
#include <vector>

using namespace std;

Words words(vector<string> {
  "importance", "inflation", "information", "innovation"
});

double prob(char c1, char c2) {
  string s1(1, c1);
  string s2(1, c2);
  if (words.freq(s1 + s2) > 0) {
    return static_cast<double>(words.freq(s1 + s2)) / (words.freq(s1) - words.freqE(s1));
  } else {
    return 0;
  }
}

int main() {
  char c1 = 'n';
  char c2 = 'f';
  
  cout << "words.freq(" << c1 << c2 << ") = " << words.freq(string(1, c1) + string(1, c2)) << endl;
  cout << "words.freq(" << c1 << ") = " << words.freq(string(1, c1)) << endl;
  cout << "words.freqE(" << c1 << ") = " << words.freqE(string(1, c1)) << endl;
  cout << "prob(" << c1 << ", " << c2 << ") = " << prob(c1, c2) << endl;
  return 0;
}