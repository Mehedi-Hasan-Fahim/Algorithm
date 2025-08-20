#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int>divisors;

void countDivisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int x = i;
            int y = n/i;
            divisors.insert(x);
            divisors.insert(y);
        }
    }
}

int main() {
    int n,k;
    cout << "Enter Number: ";
    cin >> n;
    countDivisors(n);
    cout << "Enter kth divisors: ";
    cin >> k;
    vector<int> v;
    v.assign(divisors.begin(),divisors.end());
    if(k>v.size()) cout<<"invalid input"<<endl;
    else cout<<n<<"'s "<<k<<"th divisor :"<<v[k-1]<<endl;
    divisors.clear();
    return 0;
}
