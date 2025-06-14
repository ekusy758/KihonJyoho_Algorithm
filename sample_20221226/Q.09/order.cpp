#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#define PRINT(n, str) printf("%4d���o�� (%s)\n", n, str);

using namespace std;

// �֋X��A�擪�v�f�ɋ�z������Ă��܂�
vector<vector<int>> tree = {{}, {2, 3}, {4, 5}, {6, 7}, {8, 9},
                            {10, 11}, {12, 13}, {14}, {}, {}, {},
                            {}, {}, {}, {}};

void order(int n) {
  cout << "�Zorder(" << n << ")" << endl;
  if (tree[n].size() == 2) {
    order(tree[n][0]);
    PRINT(n, "if�u���b�N");
    order(tree[n][1]);
  } else if (tree[n].size() == 1) {
    order(tree[n][0]);
    PRINT(n, "else if�u���b�N");
  } else {
    PRINT(n, "else�u���b�N");
  }
}

int main(void){
    order(1);
    return 0;
}
