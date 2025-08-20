#include <iostream>
using namespace std;
 
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
 
int main(){
 int x,y;
 int gcd=extended_euclid(12,8,x,y);
 cout<<gcd<<" "<<x<<" "<<y<<endl;
 return 0;
}
