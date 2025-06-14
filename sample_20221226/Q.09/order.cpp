#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#define PRINT(n, str) printf("%4dを出力 (%s)\n", n, str);

using namespace std;

// 便宜上、先頭要素に空配列を入れています
vector<vector<int>> tree = {{}, {2, 3}, {4, 5}, {6, 7}, {8, 9},
                            {10, 11}, {12, 13}, {14}, {}, {}, {},
                            {}, {}, {}, {}};

void order(int n) {
  cout << "〇order(" << n << ")" << endl;
  if (tree[n].size() == 2) {
    order(tree[n][0]);
    PRINT(n, "ifブロック");
    order(tree[n][1]);
  } else if (tree[n].size() == 1) {
    order(tree[n][0]);
    PRINT(n, "else ifブロック");
  } else {
    PRINT(n, "elseブロック");
  }
}

int main(void){
    order(1);
    return 0;
}
