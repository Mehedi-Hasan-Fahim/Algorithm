#include<iostream>
#include <vector>
using namespace std;

void printDivisors(int n,vector<int>&  divisors) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) 
          divisors.push_back(i);
    }
}

int main() {
    int number;
    cout<<"Enter a Number:";
    cin>>number;
    vector<int> divisors;
    printDivisors(number,divisors);

    cout << "Divisors of " << number << " are: ";
    for (int i :divisors)
        cout <<i<< " ";
    
    cout <<endl;
    return 0;
}
                                
                            
