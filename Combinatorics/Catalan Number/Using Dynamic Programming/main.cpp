#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the nth Catalan number using Dynamic Programming
unsigned long long catalan(int n) {
    vector<int> C(n + 1, 0);
    C[0] = 1; // Base case
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            C[i] = C[i] + C[j] * C[i - 1 - j];
        }
    }
    return C[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Calculate Catalan number for given n
     int C_n = catalan(n);
     cout << "Catalan number C(" << n << ") = " << C_n << endl;

    // Applying Catalan number to the 4 problems

    // Problem 1: Number of Dyck Words
    cout << "1. Number of Dyck Words of length " << 2 * n << ": " << C_n << endl;

    // Problem 2: Number of valid parentheses expressions
    cout << "2. Number of valid parentheses expressions with " << n << " pairs: " << C_n << endl;

    // Problem 3: Number of complete binary trees with " << n << " leaves
    cout << "3. Number of complete binary trees with " << n << " leaves: " << C_n << endl;

    // Problem 4: Number of ways to triangulate a polygon with " << n+2 << " sides
    cout << "4. Number of ways to triangulate a polygon with " << n + 2 << " sides: " << C_n << endl;

    return 0;
}
