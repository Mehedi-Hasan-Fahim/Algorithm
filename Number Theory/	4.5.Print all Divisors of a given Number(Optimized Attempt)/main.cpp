#include<iostream>
#include <vector>
#include <algorithm>  // To use the sort function

using namespace std;

void printDivisors(int n, vector<int>& divisors) {
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if (i != n/i) // Avoid adding the same divisor twice
                divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());  // Sorting the divisors
}
int main() {
    int number;
    cout<<"Enter a Number:";
    cin>>number;
    vector<int> divisors;
    printDivisors(number,divisors);

    cout << "Divisors of " << number << " are: ";
    for (int i :divisors)
        cout <<i<< " ";
    
    cout <<endl;
    return 0;
}
