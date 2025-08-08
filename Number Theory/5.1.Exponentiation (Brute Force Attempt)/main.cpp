#include <iostream>
using namespace std;
int main()
{
    int base,power;
    cout<<"Enter Base & Power:";
    cin>>base>>power;
    int result=1;
    for(int i=1;i<=power;i++)
       result*=base;
    
    cout<<base<<"^"<<power<<" :"<<result<<endl;

    return 0;
}
