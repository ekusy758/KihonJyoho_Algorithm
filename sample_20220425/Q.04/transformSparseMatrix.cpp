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

int main() {
  vector<vector<int>> input = {
    {3, 0, 0, 0, 0},
    {0, 2, 2, 0, 0},
    {0, 0, 0, 1, 3},
    {0, 0, 0, 2, 0},
    {0, 0, 0, 0, 1}
  };

  vector<vector<int>> output = transformSparseMatrix(input);
  size_t rows = output.size();
  size_t cols = output[0].size();

  cout << "[sparseMatrix]\n{";
  for (int i = 0; i < rows; i++) {
    cout << "{";
    for (int j = 0; j < cols; j++) {
      cout << output[i][j];
      if (j < cols - 1) cout << ", ";
    }
    cout << "}";
    if (i < rows - 1) cout << ", ";
  }
  cout << "}" << endl;

  return 0;
}