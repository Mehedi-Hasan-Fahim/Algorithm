#include <iostream>
using namespace std;

const int lim_nCr = 10;  // n এবং r এর সর্বোচ্চ মান নির্ধারণ, ১০ পর্যন্ত কাজ করবে
int ncr[lim_nCr + 1][lim_nCr + 1];  // ডিপি টেবিল

// nCr টেবিল তৈরি করার ফাংশন
void calculate_nCr() {
    // C(0, 0) = 1
    ncr[0][0] = 1;

    for (int n = 1; n <= lim_nCr; n++) {
        for (int r = 0; r <= lim_nCr; r++) {
            if (r > n)
                ncr[n][r] = 0;  // যদি r > n হয়, তখন 0
            else if (r == 0 || r == n)
                ncr[n][r] = 1;  // যদি r = 0 বা r = n হয়, তখন 1
            else
                ncr[n][r] = ncr[n - 1][r - 1] + ncr[n - 1][r];  // পুনরাবৃত্ত সূত্র প্রয়োগ
        }
    }
}

// main ফাংশন
int main() {
    calculate_nCr();  // nCr টেবিল তৈরি

    int n, r;
    cout << "Enter the value of n and r: ";
    cin >> n >> r;

    // সীমা পরীক্ষা করা
    if (n <= lim_nCr && r <= lim_nCr) {
        cout << "C(" << n << ", " << r << ") = " << ncr[n][r] << endl;
    } else {
        cout << "n or r exceeds the limit (" << lim_nCr << ")" << endl;
    }

    return 0;
}
