#include <iostream>
#include <vector>
using namespace std;
using matrix = vector<vector<long long>>; // For handling large Fibonacci numbers

const long long MOD = 1e9+7; // To handle large numbers, taking mod

// Function to multiply two matrices
matrix multiplyMatrices(matrix A, matrix B) {
    int r1 = A.size();
    int c1 = A[0].size();
    int r2 = B.size();
    int c2 = B[0].size();
    if (c1 != r2) {
        throw invalid_argument("Matrix dimensions do not match for multiplication.");
    }
    matrix C(r1, vector<long long>(c2, 0));
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD; // Take mod for each operation
            }
        }
    }
    return C;
}

// Function to perform matrix exponentiation
matrix matrixExponentiation(matrix base, long long power) {
    int size = base.size();
    matrix result(size, vector<long long>(size, 0));

    // Initialize result as identity matrix
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while (power > 0) {
        if (power % 2 == 1) {
            result = multiplyMatrices(result, base);
        }
        base = multiplyMatrices(base, base);
        power /= 2;
    }
    return result;
}

// Function to calculate Fibonacci using matrix exponentiation
long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Transformation matrix
    matrix T = {
        {1, 1},
        {1, 0}
    };

    // Calculate T^(n-1)
    matrix result = matrixExponentiation(T, n - 1);

    // The top-left cell of the resulting matrix gives Fn
    return result[0][0];
}

// Main function
int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number F(" << n << ") is: " << fibonacci(n) << endl;
    return 0;
}
