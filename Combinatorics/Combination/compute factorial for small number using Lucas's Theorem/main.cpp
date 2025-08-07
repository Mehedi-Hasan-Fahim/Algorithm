#include <iostream>
using namespace std;

const int MOD = 5; // এখানে p একটি প্রাইম সংখ্যা হিসেবে 5 নেওয়া হয়েছে

// সিম্পল nCr % p গণনা করে, যেখানে n এবং r ছোট এবং p এর চেয়ে ছোট
int simpleNCrModP(int n, int r, int p) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    int result = 1;
    for (int i = 0; i < r; i++) {
        result = result * (n - i) % p; // Multiply with (n - i) mod p
    }
    return result;
}

// Lucas's Theorem অনুযায়ী nCr % p বের করা
int lucasTheorem(int n, int r, int p) {
    if (r == 0) return 1;

    // n এবং r এর বর্তমান বেজ p এর প্রতিটি ডিজিট বের করা
    int ni = n % p;
    int ri = r % p;

    // রিকার্সিভভাবে Lucas's Theorem প্রয়োগ করা এবং ডিজিট-বাই-ডিজিট nCr নির্ণয়
    return (lucasTheorem(n / p, r / p, p) * simpleNCrModP(ni, ri, p)) % p;
}

int main() {
    int n = 20, r = 4;

    // nCr এর মান প্রিন্ট করা
    cout << "nCr(" << n << ", " << r << ") mod " << MOD << " = " << lucasTheorem(n, r, MOD) << endl;

    return 0;
}
