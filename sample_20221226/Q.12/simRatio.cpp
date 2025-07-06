#include <iostream>
#include <vector>

using namespace std;

double simRatio(vector<char> s1, vector<char> s2) {
  int i, cnt = 0;
  if (s1.size() != s2.size()) {
    return -1;
  }
  for (i = 0; i < s1.size(); i++) {
    if (s1[i] == s2[i]) {
      cnt = cnt + 1;
    }
  }
  return static_cast<double>(cnt) / s1.size();
}

int main() {
  vector<char> src = {'a', 'p', 'p', 'l', 'e'};
  cout << simRatio(src, vector<char>{'a', 'p', 'p', 'l', 'e'}) << endl;
  cout << simRatio(src, vector<char>{'a', 'p', 'r', 'i', 'l'}) << endl;
  cout << simRatio(src, vector<char>{'m', 'e', 'l', 'o', 'n'}) << endl;
  cout << simRatio(src, vector<char>{'p', 'e', 'n'}) << endl;
}