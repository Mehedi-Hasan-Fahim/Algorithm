#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the number of digits in n! using Stirling's approximation
int findDigits(int n)
{
 // Factorial exists only for n >= 0
 if (n < 0)
    return 0;

 // Base case for n <= 1, factorial is 1, which has 1 digit
 if (n <= 1)
    return 1;

 // Use Stirling's approximation to compute the number of digits in n!
 //double pi = 2 * acos(0.0);
 double x = (0.5 * log10(2 * 3.1416 * n)) + (n * log10(n / 2.71828))+1 ;

 // Return the number of digits (floor(x) + 1)
 return x;
}

// Driver code
int main()
{
 cout << findDigits(10) << endl; // Example test case
 return 0;
}
