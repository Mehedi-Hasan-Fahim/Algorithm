#include<iostream>
using namespace std;

int stirling_num_second_kind(int n,int k){
    if(k > n) return 0;
    if(k == 0 && n == 0 ) return 1;
    if(k == n || k == 1 ) return 1;
    
    return  stirling_num_second_kind(n-1,k-1) + k*stirling_num_second_kind(n-1,k);
}

int main(){
    /* S(n,k) এর মানে হল আমাদের কাছে nটি জিনিস আছে  এবং আমরা এগুলোকে k ভাগে ভাগ করতে চাই , 
       S(n,k) এর মানই হল কত ভাবে এই ভাগ করা যাবে। */
    int n,k;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"S("<<n<<","<<k<<") = "<<stirling_num_second_kind( n, k);
    
}