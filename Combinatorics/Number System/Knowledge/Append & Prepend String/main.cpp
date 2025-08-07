#include <bits/stdc++.h>
using namespace std;

int main() {
   string append_str="";
   string prepend_str="";
   char input;
   for(int i=0;i<5;i++){
       cin>>input;
       append_str =append_str+input;
       prepend_str=input+prepend_str;
   }
   cout<<"Append String:"<<append_str<<endl;
   cout<<"Prepend String:"<<prepend_str<<endl;
   

    return 0;
}