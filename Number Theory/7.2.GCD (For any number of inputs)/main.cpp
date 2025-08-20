#include<iostream>
#include<vector>
using namespace std;

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to compute GCD of a list of numbers
int gcd_of_list(vector<int>& numbers) {
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); i++) 
        result = gcd(result,numbers[i]);
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of inputs for GCD: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Calculate GCD of the entire list
    int gcd = gcd_of_list(numbers);
    cout << "The GCD of the numbers is: " << gcd << endl;

    return 0;
}
