#include<iostream>
using namespace std;

void prime_fact(int n){
    for(int i =2;i<=n;i++){
        if(n%i==0){
            int count =0;
            while(n%i==0){
                count++;
                n/=i;
            }
            cout<<i<<" ^ "<<count<<"  ";
        }
    }
}

int main(){
    int input;
    cout<<"Enter Input:";
    cin>>input;
    prime_fact(input);
    
}
