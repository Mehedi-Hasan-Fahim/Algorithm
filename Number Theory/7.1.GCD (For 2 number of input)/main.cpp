#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b == 0) return a;
    /* if(a%b == 0) return b; a কে b দিয়ে ভাগ দিব ,যদি নিঃশেষে ভাগ যায় তাহলে b ই GCD
    */
    return gcd(b,a%b);/* a কে b দিয়ে ভাগ দিয়ে যদি নিঃশেষে ভাগ না যায় তখন যে ভাগশেষ 
                        পাওয়া যায় সেটির সাথে b এর পূর্বের ন্যায় gcd বের করা
                    */
}

int main(){
    int a,b;
    cout<<"Enter Input For GCD:";
    cin>>a>>b;
    cout<<a<<" & "<<b<<"'s GCD is "<<gcd(a,b);
}
