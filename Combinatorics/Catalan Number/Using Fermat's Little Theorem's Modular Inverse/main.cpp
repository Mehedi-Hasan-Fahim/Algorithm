#include <iostream>
using namespace std;

const int MOD = 1e9 + 7; // একটি বড় প্রাইম সংখ্যা হিসেবে 10^9+7 নেওয়া হয়েছে
const int MAX = 1e5 + 5;
long long factorial[MAX];

// ফ্যাক্টোরিয়াল পূর্বরূপে গণনা করা
void computeFactorials(int n) {
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}

// Fermat's Little Theorem অনুযায়ী মডুলার ইনভার্স বের করা
long long modInverse(long long a, long long p) {
    long long res = 1;
    int exponent = p - 2; // MOD প্রাইম হলে, a^(p-2) হল a এর ইনভার্স
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = res * a % p;
        }
        a = a * a % p;
        exponent /= 2;
    }
    return res;
}

// nCr এর মান নির্ণয় করা
long long nCr(int n, int r) {
    if (r > n) return 0;
    long long numerator = factorial[n];
    long long denominator = factorial[r] * factorial[n - r] % MOD;
    return numerator * modInverse(denominator, MOD) % MOD;
}

// ক্যাটালান সংখ্যা নির্ণয়
long long catalan(int n) {
    // C_n = (1 / (n + 1)) * C(2n, n) (MOD এর মধ্যে)
    long long c = nCr(2 * n, n);
    return c * modInverse(n + 1, MOD) % MOD; // (n + 1)^(-1) হলো মডুলার ইনভার্স
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // প্রয়োজনীয় ফ্যাক্টোরিয়ালগুলো গণনা করা
    computeFactorials(2 * n);

    // ক্যাটালান সংখ্যা প্রিন্ট করা
    cout << "Catalan number C(" << n << ") mod " << MOD << " = " << catalan(n) << endl;
    // Problem 1: Number of Dyck Words
    cout << "1. Number of Dyck Words of length " << 2 * n << ": " << catalan(n) << endl;

    // Problem 2: Number of valid parentheses expressions
    cout << "2. Number of valid parentheses expressions with " << n << " pairs: " << catalan(n) << endl;

    // Problem 3: Number of complete binary trees with " << n << " leaves
    cout << "3. Number of complete binary trees with " << n << " leaves: " << catalan(n) << endl;

    // Problem 4: Number of ways to triangulate a polygon with " << n+2 << " sides
    cout << "4. Number of ways to triangulate a polygon with " << n + 2 << " sides: " << catalan(n) << endl;


    return 0;
}
