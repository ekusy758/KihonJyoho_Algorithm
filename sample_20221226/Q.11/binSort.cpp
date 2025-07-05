#include <iostream>
#include <vector>

using namespace std;

vector<int> binSort(vector<int> data) {
  int n = data.size();
  vector<int> bins = data;
  int i;

  for (i = 0; i < n; i++) {
    bins.at(data[i] - 1) = data[i];
  }

  return bins;
}

/* Same as the sample_20221226 Q3 */
void printVector(vector<int> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i < vec.size() - 1) cout << ", ";
  }
  cout << "}" << endl;
}

int main() {
  try {
    vector<int> v = binSort(vector<int>{2, 6, 3, 1, 4, 5});
    printVector(v);
  } catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
  }
  return 0;
}