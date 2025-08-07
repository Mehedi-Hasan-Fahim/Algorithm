/*#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>*/

#include<bits/stdc++.h>

using namespace std;

// Function to convert a decimal number to a given base as a string
string fromDecimal(int decimal, int base) {
    if (decimal == 0) return "0";
    string result = "";
    cout<<decimal<<" remainder"<<endl;
    while (decimal > 0) {
        int remainder = decimal % base;
        char digit = (remainder < 10) ? '0' + remainder : 'A' + (remainder - 10);
        result = digit + result;
        decimal /= base;
        cout<<decimal<<" --> "<<digit<<" "<<result<<endl;
    }
    return result;
}


int main() {
   int decimalValue=12123;
   cout<<"Binary:"<<endl;
   
   string binary = fromDecimal(decimalValue, 2);
   cout<<binary<<endl;
  
   cout<<"Octal:"<<endl;
   binary = fromDecimal(decimalValue, 8);
   cout<<binary<<endl;
   
   cout<<"Hexa:"<<endl;
   binary = fromDecimal(decimalValue, 16);
   cout<<binary<<endl;
    return 0;
}