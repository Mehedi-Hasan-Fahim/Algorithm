#include <iostream>
#include <algorithm>
using namespace std;

string subtractBigIntegers(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    cout<<"Reversed String"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;

    string result = "";
    int borrow = 0;

    int n1 = num1.size(), n2 = num2.size();

    for (int i = 0; i < n1; i++) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < n2) ? num2[i] - '0' : 0;

        digit1 -= borrow;

        if (digit1 < digit2) {
            cout<<digit1<<"<"<<digit2<<","<<digit1<<"+10 ->";
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.push_back((digit1 - digit2) + '0');
        cout<<digit1<<"-"<<digit2<<"="<<digit1-digit2<<" borrow:"<<borrow<<endl;
    }
    cout<<"Result:"<<result<<endl;
    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cout << "Enter two large numbers (num1 > num2): ";
    cin >> num1 >> num2;
    string differences = subtractBigIntegers(num1, num2);
    cout <<"Difference: " << differences << endl;
    return 0;
}
