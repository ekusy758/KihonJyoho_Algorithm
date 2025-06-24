#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transformSparseMatrix(vector<vector<int>> matrix) {
  int i, j;
  vector<vector<int>> sparseMatrix(3);
  for (i = 0; i < matrix.size(); i++) {
    for (j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] != 0) {
        sparseMatrix[0].push_back(i + 1); // 問題の仕様に結果を合わせるため+1する
        sparseMatrix[1].push_back(j + 1); // 問題の仕様に結果を合わせるため+1する
        sparseMatrix[2].push_back(matrix[i][j]);
      }
    }
  }
  return sparseMatrix;
}

void printVector2D(vector<vector<int>> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << "{";
    for (int j = 0; j < vec[i].size(); j++) {
      cout << vec[i][j];
      if (j < vec[i].size() - 1) cout << ", ";
    }
    cout << "}";
    if (i < vec.size() - 1) cout << ", ";
  }
  cout << "}" << endl;
}

int main() {
  vector<vector<int>> input = {
    {3, 0, 0, 0, 0},
    {0, 2, 2, 0, 0},
    {0, 0, 0, 1, 3},
    {0, 0, 0, 2, 0},
    {0, 0, 0, 0, 1}
  };
  
  vector<vector<int>> output = transformSparseMatrix(input);
  printVector2D(output);

  return 0;
}