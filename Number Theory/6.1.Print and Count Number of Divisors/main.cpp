#include <iostream>
#include <set>
using namespace std;

set<int> divisors;

void countDivisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int x = i;
            int y = n / i;
            divisors.insert(x);
            if (x != y) { // Avoid inserting duplicates
                divisors.insert(y);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;
    countDivisors(n);
    cout << "Number of Divisors: " << divisors.size() << endl;
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;
    divisors.clear();
    return 0;
}
