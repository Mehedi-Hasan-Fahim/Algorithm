#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Basic sieve to find primes up to sqrt(high)
void simpleSieve(int limit, vector<int>& primes) {
	vector<bool> isPrime(limit, true);
	for (int i = 2; i * i <= limit; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= limit; j += i)
				isPrime[j] = false;
		}
	}
	for (int i = 2; i <= limit; i++) {
		if (isPrime[i])
			primes.push_back(i);
	}
}

// Segmented sieve to find primes in range [low, high]
void segmentedSieve(int low, int high) {
	// Step 1: Find all primes up to sqrt(high)
	int limit = sqrt(high);
	vector<int>primes;
	simpleSieve(limit, primes);

	// Step 2: Create a boolean array for the range [low, high]
	vector<bool> isPrime(high - low + 1, true);

	// Step 3: Use primes to mark non-prime numbers in the range [low, high]
	for (int prime : primes) {
		// Find the first number in the range [low, high] that is a multiple of 'prime'

		int start = max(prime * prime, (low + prime - 1) / prime * prime);


		// Mark multiples of 'prime' as non-prime
		for (int j = start; j <= high; j += prime)
			isPrime[j - low] = false;
	}

	// Step 4: Special case when low is 1 (1 is not a prime number)
	if (low == 1)
		isPrime[0] = false;

	// Step 5: Print all primes in the range [low, high]
	int count = 0;
	cout << "Prime numbers between " << low << " and " << high << " are: ";
	for (int i = 0; i <= high - low; i++) {
		if (isPrime[i]) {
			count++;
			cout << (i + low) << " "; // i + low gives the actual number in the range
		}
	}
	cout << endl << "Number of primes in the range [" << low << ", " << high << "] --> " << count << endl;
}

int main() {
	int low, high;
	cout << "Enter the lower bound of the range: ";
	cin >> low;
	cout << "Enter the upper bound of the range: ";
	cin >> high;

	segmentedSieve(low, high);


	return 0;
}
