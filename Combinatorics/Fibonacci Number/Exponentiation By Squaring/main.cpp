#include <iostream>
using namespace std;
/*
formula:  when n = 0  , a^n = 1
          when n =even, a^n = a^(n/2) * a^(n/2)  
          when is n odd a^n = a * a^(n-1) 
           as we are working with integer number so we can replace a^n = a * a^(n-1) with
           a^n = a * a^(n/2) * a^(n/2) casue
           2^5 =   2^(5/2)  * 2^(5/2)  = 2^(2)  * 2^(2) = 2^4 = 2^(5-1) =2^(n-1)

*/

long Exponentiation_by_Squaring(int base, int power) {
    long result = 1; // Initialize result to 1
    if (power < 0) {
        cout << "Negative powers are not supported with integer types." << endl;
        return -1; // Indicate an error for unsupported negative powers
    }

    if (power == 0) {
        return 1; // Any number raised to the power of 0 is 1
    }

    long temp = Exponentiation_by_Squaring(base, power / 2);

    if (power % 2 == 0) {
        return temp * temp; // If power is even
    } else {
        return base * temp * temp; // If power is odd
    }
    
    /*
    else if (power % 2 == 0) {                                        // Even case
        long half = Exponentiation_by_Squaring(base, power / 2);
        result = half * half;                                        // Reuse the result of half
        return result;
    } else {
        result = base * Exponentiation_by_Squaring(base, power - 1); // Odd case
        return result;
    }*/
}

int main() {
    int base, power;
    cout << "Enter Base & Power: ";
    cin >> base >> power;

    long result = Exponentiation_by_Squaring(base, power);

    if (result != -1) { // Check for valid result
        cout << base << "^" << power << " : " << result << endl;
    }
}
