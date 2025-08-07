#include <iostream>
#include <algorithm>
using namespace std;

string addBigIntegers(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    cout<<"Reversed String"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;

    string result = "";
    int carry = 0, i;

    int n1 = num1.size(), n2 = num2.size();
    int maxLen = max(n1, n2);

    for (i = 0; i < maxLen; i++) {
        int digit1 = (i < n1) ? num1[i] - '0' : 0;
        int digit2 = (i < n2) ? num2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back((sum % 10) + '0');// Add the last digit of sum to result
        carry = sum / 10;// Carry over to the next digit
        cout<<digit1<<" + "<<digit2<<"="<<sum<<" carry:"<<carry<<endl;
    }

    if (carry > 0) result.push_back(carry + '0');

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cout << "Enter two large numbers: ";
    cin >> num1 >> num2;
    string sum = addBigIntegers(num1, num2);
    cout << "Sum: " << sum << endl;
    return 0;
}
