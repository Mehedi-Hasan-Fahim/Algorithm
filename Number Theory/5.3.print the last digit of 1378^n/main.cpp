#include <iostream>
using namespace std;


/* Binary Exponentiation Algorithm Idea 

2^9=512

res   base   power 
1     2       9
2     2       8 
2     4       4 
2     16      2 
2     156     1
512   156     0 

*/

int Binary_Exponentiation(int base,int power){
    int result=1;
    while(power){
        if(power%2 != 0){
            result=(result*base)%10;
            power-=1;
        }
        else{
            base=(base*base)%10;
            power/=2;
        }
    }
    
    return result;
}


int main()
{   
    int base,power;
    cout<<"Enter Base & Power:";
    cin>>base>>power;
    cout<<"The last digit of "<<base<<"^"<<power<<" is:";
    base=base%10;
    cout<<Binary_Exponentiation(base,power);

    return 0;
}
