#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>

using namespace std;

// Function to convert a number from a given base to decimal
int toDecimal(const string& input, int base) {
    int decimalValue = 0;
    int power = 1;
    for (int i = input.length() - 1; i >= 0; i--) {
        char digit = input[i];
        int value = (digit >= '0' && digit <= '9') ? digit - '0' : toupper(digit) - 'A' + 10;
        decimalValue += value * power;
        power *= base;
    }
    return decimalValue;
}

// Function to convert a decimal number to a given base as a string
string fromDecimal(int decimal, int base) {
    if (decimal == 0) return "0";
    string result = "";
    while (decimal > 0) {
        int remainder = decimal % base;
        char digit = (remainder < 10) ? '0' + remainder : 'A' + (remainder - 10);
        result = digit + result;
        decimal /= base;
    }
    return result;
}

// Function to format binary output into groups of 4
string formatBinary(const string& binary) {
    string paddedBinary = binary;

    // Pad the binary string with leading zeros to make its length a multiple of 4
    int remainder = binary.length() % 4;
    if (remainder != 0) {
        int padding = 4 - remainder;
        paddedBinary = string(padding, '0') + binary;
    }

    // Format the padded binary string
    string formatted;
    int count = 0;
    for (char c : paddedBinary) {
        if (count > 0 && count % 4 == 0) formatted += ' ';
        formatted += c;
        count++;
    }

    return formatted;
}


int main() {
    string input;
    int base;

    cout << "Enter Input: ";
    cin >> input;
    cout << "Enter Base Of Input: ";
    cin >> base;

    // Convert input to decimal
    int decimalValue = toDecimal(input, base);

    // Convert decimal to other bases
    string binary = fromDecimal(decimalValue, 2);
    string octal = fromDecimal(decimalValue, 8);
    string hex = fromDecimal(decimalValue, 16);

    // Output the results
    cout << "\nConversion:" << endl;
    cout << "Input: " << input << endl;
    if (base != 10)cout << "Decimal: " << decimalValue << endl;
    if (base != 2) cout << "Binary: " << formatBinary(binary) << endl;
    if (base != 8) cout << "Octal: " << setfill('0') << setw(4) << octal << endl;
    if (base != 16) cout << "Hexa: " << setfill('0') << setw(4) << hex << endl;

    return 0;
}
