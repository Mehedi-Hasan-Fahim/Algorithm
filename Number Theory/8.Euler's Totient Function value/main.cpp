#include<iostream>
#include<vector>
using namespace std;

// Function to find prime factors
void prime_fact(int n, vector<int>& prime_factorization) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            prime_factorization.push_back(i); // Add distinct prime factor
        }
    }
    
    if (n > 1) {
        prime_factorization.push_back(n); // If n is prime
    }
}

// Function to calculate Euler's Totient Function
int euler_totient(int n, vector<int>& prime_factorization) {
    int result = n;
    for (int prime : prime_factorization) {
        result = result * (prime - 1) / prime; // Applying the formula  
        /*  
            ϕ(n) = n(1-1/p1)(1-1/p2)...
                 = n * {(p1-1)/p1} * {(p2-1)/p2}
        */
    }
    return result;
}

int main() {
    int input;
    cout << "Enter Input: ";
    cin >> input;
    
    vector<int> prime_factorization;
    prime_fact(input, prime_factorization);
    
    int totient = euler_totient(input, prime_factorization); // Calculate totient
    
    cout << "Euler's Totient Function value  ϕ("<<input<<") : " << totient << endl;
    
    return 0;
}
