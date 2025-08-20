#include<iostream>
#include<vector>
using namespace std;

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to compute LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);  // Use GCD of the two numbers
}

// Function to compute GCD & LCM of a list of numbers
void gcd_lcm_of_list(vector<int>& numbers, int& gcd_result, int& lcm_result) {
   for (int i = 1; i < numbers.size(); i++) {
        gcd_result = gcd(gcd_result, numbers[i]);
        lcm_result = lcm(lcm_result, numbers[i]);
    }
}

int main() {
    int n;
    cout << "Enter the number of inputs for GCD and LCM: ";
    cin >> n;

    // Handle edge case where no inputs are provided
    if (n <= 0) {
        cout << "You must enter at least one number." << endl;
        return 1;
    }

    vector<int> numbers(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Initializing GCD and LCM with the first number
    int gcd_result = numbers[0];
    int lcm_result = numbers[0];

    // If there's more than one number, calculate GCD and LCM
    if (n > 1) {
        gcd_lcm_of_list(numbers, gcd_result, lcm_result);
    }

    // Display results
    cout << "The GCD of the numbers is: " << gcd_result << endl;
    cout << "The LCM of the numbers is: " << lcm_result << endl;

    return 0;
}
