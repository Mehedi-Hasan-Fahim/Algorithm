#include <iostream>
#include <cstring>
using namespace std;

void sieve(int n){
    int prime[n];
    
    memset(prime,0,sizeof(prime));
    
    for(int i=2 ;i*i<=n;i++){
        if(prime[i]==0){
            
            for(int j=i*i;j<=n;j+=i){
                prime[j] = 1;
            }
        }
    }
    int count=0;
    for(int i=2;i<=n;i++){
        
        if(prime[i]==0){
            count++;
            cout<<i<<" ";
            
        }
    }
    cout<<"--> "<<count;
 
}


int main()
{
    cout<<"Enter Number:";
    int n;
    cin>>n;
    sieve(n);

    return 0;
}
