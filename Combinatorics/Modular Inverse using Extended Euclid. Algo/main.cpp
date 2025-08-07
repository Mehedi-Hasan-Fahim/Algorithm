#include <iostream>

using namespace std;

// এক্সটেন্ডেড ইউক্লিডিয়ান অ্যালগোরিদম
int extended_euclid(int a,int b,int &x,int &y){
    if(b==0){
             x=1;
             y=0;
            return a;
    }
             int x1,y1;
             int gcd=extended_euclid(b,a%b,x1,y1);
             x=y1;
             y=x1-(a/b)*y1;
        
 return gcd;
}

// মডুলার ইনভার্স বের করার ফাংশন
int modularInverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);

    if (g != 1)
        return -1; // মডুলার ইনভার্স নেই

    return (x % m + m) % m;
}

int main() {
    int a, m;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter m: ";
    cin >> m;

    int inv = modularInverse(a, m);

    if (inv != -1)
        cout << "Modular inverse of " << a << " mod " << m << " is " << inv << endl;
    else
        cout << "Modular inverse does not exist" << endl;

    return 0;
}