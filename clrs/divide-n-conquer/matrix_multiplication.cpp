#include <iostream>
#include <array>

using namespace std;

using Matrix = std::array<std::array<double, 2>, 2>;

void printMatrix(const Matrix& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << '\t';
        }
        cout << '\n';
    }
}

void matrixMultiply(const Matrix& a, const Matrix& b, Matrix& c, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


void matrixMultiplyRecursive(const Matrix& a, int aRow, int aCol, const Matrix& b, int bRow,
                             int bCol, Matrix& c, int cRow, int cCol, int n) {
    if (n == 1) {
        c[cRow][cCol] += a[aRow][aCol] * b[bRow][bCol];
        return;
    }

    // C_11 = A_11 * B_11 + A_12 * B_21
    matrixMultiplyRecursive(a, 0, 0, b, 0, 0, c, 0, 0, n / 2);
    matrixMultiplyRecursive(a, 0, n / 2, b, n / 2, 0, c, 0, 0, n / 2);

    // C_12 = A_11 * B_12 + A_12 * B_22
    matrixMultiplyRecursive(a, 0, 0, b, 0, n / 2, c, 0, n / 2, n / 2);
    matrixMultiplyRecursive(a, 0, n / 2, b, n / 2, n / 2, c, 0, n / 2, n / 2);

    // C_21 = A_21 * B_11 + A_22 * B_21
    matrixMultiplyRecursive(a, n / 2, 0, b, 0, 0, c, n / 2, 0, n / 2);
    matrixMultiplyRecursive(a, n / 2, n / 2, b, n / 2, 0, c, n / 2, 0, n / 2);

    // C_22 = A_21 * B_12 + A_22 * B_22
    matrixMultiplyRecursive(a, n / 2, 0, b, 0, n / 2, c, n / 2, n / 2, n / 2);
    matrixMultiplyRecursive(a, n / 2, n / 2, b, n / 2, n / 2, c, n / 2, n / 2, n / 2);
}

void matrixMultiplyRecursiveWithFor(const Matrix& a, int aRow, int aCol, const Matrix& b, int bRow,
                                    int bCol, Matrix& c, int cRow, int cCol, int n) {
    if (n == 1) {
        c[cRow][cCol] += a[aRow][aCol] * b[bRow][bCol];
        return;
    }

    // Will expand to 8 recursive calls same as those in matrixMultiplyRecursive()
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                matrixMultiplyRecursiveWithFor(a, i * n / 2, k * n / 2, b, k * n / 2, j * n / 2, c,
                                               i * n / 2, j * n / 2, n / 2);
            }
        }
    }
}

int main() {
    Matrix a = {{{1, 2}, {3, 4}}};
    Matrix b = {{{2, 3}, {4, 5}}};
    Matrix c = {{0}};
    Matrix d = {{0}};
    Matrix e = {{0}};

    cout << "a:\n";
    printMatrix(a, 2);
    cout << "\nb:\n";
    printMatrix(b, 2);

    cout << "\nmatrix multiplication by triple for loop:\n";
    matrixMultiply(a, b, c, 2);
    printMatrix(c, 2);

    cout << "\nmatrix multiplication by recursion:\n";
    matrixMultiplyRecursive(a, 0, 0, b, 0, 0, d, 0, 0, 2);
    printMatrix(d, 2);

    cout << "\nmatrix multiplication by recursion with for loops:\n";
    matrixMultiplyRecursiveWithFor(a, 0, 0, b, 0, 0, e, 0, 0, 2);
    printMatrix(e, 2);

    return 0;
}