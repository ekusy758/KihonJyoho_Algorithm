#include <iostream>
#include <vector>

using namespace std;

vector<int> makeNewArray(vector<int> in) {
  vector<int> out = {};
  int i, tail;
  out.push_back(in[0]);
  for (i = 1; i < in.size(); i++) {
    tail = out[out.size() - 1];
    out.push_back(tail + in[i]);
  }
  return out;
}

void printVector(vector<int> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i < vec.size() - 1) cout << ", ";
  }
  cout << "}" << endl;
}

int main() {
  vector<int> newArray = makeNewArray({3, 2, 1, 6, 5, 4});
  printVector(newArray);
}