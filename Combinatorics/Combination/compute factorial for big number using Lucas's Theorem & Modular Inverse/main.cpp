#include <iostream>
using namespace std;

const int MOD = 13; // p is assumed to be a prime number

// Array to store factorials modulo MOD
long long factorial[MOD];

// Precompute factorials modulo MOD
void computeFactorials() {
    factorial[0] = 1;
    for (int i = 1; i < MOD; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}

// Compute modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long p) {
    long long res = 1;
    int exponent = p - 2; // Since MOD is prime, a^(p-2) is the inverse of a
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = res * a % p;
        }
        a = a * a % p;
        exponent /= 2;
    }
    return res;
}

// Calculate nCr % MOD for small values of n, r < MOD
long long nCrModP(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1; // Base cases
    long long numerator = factorial[n];
    long long denominator = factorial[r] * factorial[n - r] % MOD;
    return numerator * modInverse(denominator, MOD) % MOD;
}

// Calculate nCr % p using Lucas's Theorem
long long lucasTheorem(int n, int r) {
    if (r == 0) return 1;
    
    // Get the last digits in base MOD
    int ni = n % MOD;
    int ri = r % MOD;
    
    // Recursive application of Lucas's Theorem
    return (lucasTheorem(n / MOD, r / MOD) * nCrModP(ni, ri)) % MOD;
}

int main() {
    int n = 6070, r = 400;

    // Precompute factorials mod MOD
    computeFactorials();

    // Print result of nCr % MOD
    cout << "nCr(" << n << ", " << r << ") mod " << MOD << " = " << lucasTheorem(n, r) << endl;

    return 0;
}
