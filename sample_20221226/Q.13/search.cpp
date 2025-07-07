#include <iostream>
#include <vector>

using namespace std;

/* This is binary search program. */
int search(vector<int> data, int target) {
  int low, high, middle;

  low = 0;
  high = data.size() - 1; // Bug fix

  while (low <= high) {
    middle = (low + high) / 2;
    if (data[middle] < target) {
      low = middle + 1; // Bug fix
    } else if (data[middle] > target) {
      high = middle - 1; // Bug fix
    } else {
      return middle;
    }
  }

  return -1;
}

int main() {
  vector<int> in = {1, 2, 3, 4, 5, 6}; // Require ascending order;
  cout << "in = {1, 2, 3, 4, 5, 6}" << endl;
  for (int i = 0; i < 8; i++) {
    cout << "target=" << i << ", index=" << search(in, i) << endl;
  }
}