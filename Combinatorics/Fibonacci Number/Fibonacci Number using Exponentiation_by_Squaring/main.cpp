#include <iostream>
using namespace std;

const int MOD = 1e9 + 7; // একটি বড় প্রাইম সংখ্যা হিসেবে 10^9+7 নেওয়া হয়েছে

// ফ্যাক্টোরিয়াল গণনা করার জন্য একটি অ্যারে
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

int main() {
    int n = 20, r = 5;

    // প্রয়োজনীয় ফ্যাক্টোরিয়ালগুলো গণনা করা
    computeFactorials(n);

    // nCr এর মান প্রিন্ট করা
    cout << "nCr(" << n << ", " << r << ") mod " << MOD << " = " << nCr(n, r) << endl;

    return 0;
}
