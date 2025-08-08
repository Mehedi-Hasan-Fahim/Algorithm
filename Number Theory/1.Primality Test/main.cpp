
#include <iostream>
using namespace std;

bool prime(long n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    
    for(long i=3 ; i*i<n ;i+=2 ){
        if(n%i == 0) return false;
    }
    return true;
}


int main()
{
    long int n;
    cout<<"Enter Number For Primality Test"<<endl;
    cin>>n;
    if(prime(n)){
        cout<<n<<" is a prime number";
    }else{
        cout<<n<<" is not a prime number";
    }

    return 0;
}
