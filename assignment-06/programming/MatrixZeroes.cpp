#include <iostream>
#include <vector>

using namespace std;

void makeRowZero(vector<vector<int>>& matrix, int row, int cols) {
    for (int j = 0; j < cols; j++) {
        matrix[row][j] = 0;
    }
}

void makeColZero(vector<vector<int>>& matrix, int col, int rows) {
    for (int i = 0; i < rows; i++) {
        matrix[i][col] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {

    if (matrix.empty()) {
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<bool> zeroRows(rows, false);
    vector<bool> zeroCols(cols, false);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        if (zeroRows[i]) {
            makeRowZero(matrix, i, cols);
        }
    }


    for (int j = 0; j < cols; j++) {
        if (zeroCols[j]) {
            makeColZero(matrix, j, rows);
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    cout << "Original Matrix 1:" << endl;
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "Modified Matrix 1:" << endl;
    printMatrix(matrix);

    cout << endl;

    cout << "Original Matrix 2:" << endl;
    printMatrix(matrix2);

    setZeroes(matrix2);

    cout << "Modified Matrix 2:" << endl;
    printMatrix(matrix2);

    return 0;
}