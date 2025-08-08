#include<iostream>
#include<vector>
using namespace std;
long n = 9000000 ;
vector<int> v ;

void sieve(){
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    
    for(int i=2;i*i<=n;i++ ){
        if(prime[i] == true){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = false ;
            }
        }
    }
    for(int i=2;i<=n;i++){
       if(prime[i]==true){
           v.push_back(i);
       } 
    }
}

int main(){
    sieve();
    int input;
    cout<<"Enter input:";
    cin>>input;
    cout<<v[input-1];
}


