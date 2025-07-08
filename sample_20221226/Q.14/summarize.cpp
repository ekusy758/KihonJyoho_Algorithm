#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double findRank(vector<double> sortedData, double p) {
  int i;
  i = ceil(p * (sortedData.size() - 1));
  return sortedData[i];
}

vector<double> summarize(vector<double> sortedData) {
  vector<double> rankData(0);
  vector<double> p = {0, 0.25, 0.5, 0.75, 1};
  int i;
  for (i = 0; i < p.size(); i++) {
    rankData.push_back(findRank(sortedData, p[i]));
  }
  return rankData;
}

void printVector(vector<double> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i < vec.size() - 1) cout << ", ";
  }
  cout << "}" << endl;
}

int main() {
  vector<double> v = summarize({0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1});
  printVector(v);
}