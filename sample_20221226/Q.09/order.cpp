#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree = {{}, {2, 3}, {4, 5}, {6, 7}, {8, 9},
                            {10, 11}, {12, 13}, {14}, {}, {}, {},
                            {}, {}, {}, {}};

void order(int n) {
  if (tree[n].size() == 2) {
    order(tree[n][0]);
    cout << n << ", ";
    order(tree[n][1]);
  } else if (tree[n].size() == 1) {
    order(tree[n][0]);
    cout << n << endl;
  } else {
    cout << n << ", ";
  }
}

int main(void) {
  order(1);
  return 0;
}
