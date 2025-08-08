#include<iostream>
using namespace std;

void diff_prime_fact(int n){
    
    if(n <= 1){
        cout << n <<"has no prime factors" << endl;
        return;
    }
    
    int count=0;
    // Checking for factors from 2 to sqrt(n)
    for(int i =2;i*i<=n;i++){
        if(n%i==0){
            count++; // Count the prime factor
            while(n%i==0){
                n/=i;// Remove all multiples of this prime factor
            }
        }
    }
    // If n is still greater than 1, it must be a prime number
    if(n>1)
      count++;
    cout<<count<<endl;
}
int main(){
    int input;
    cout<<"Enter Input:";
    cin>>input;
    // Calling the function to count different prime factors
    diff_prime_fact(input); 
}
