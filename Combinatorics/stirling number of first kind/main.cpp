#include<iostream>
using namespace std;

int factorial(int n) {
  if(n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}

int stirling_num_first_kind(int n,int k){
    if(k > n) return 0;
    if(n == 0 && k == 0 ) return 1;
    if(k == n) return 1;
    if(k == 1) return factorial(n-1);
    
    return  stirling_num_first_kind(n-1,k-1) + (n-1)*stirling_num_first_kind(n-1,k);
}

int main(){
    /* 
    "Stirling Number of the First Kind  সংখ্যা দিয়ে বোঝানো হয় n সংখ্যক আলাদা জিনিসকে k টি সাইকেলে ভাগ করার উপায় সংখ্যা।
    সাইকেলের মানে হলো, n টা জিনিস এমনভাবে k টি গ্রুপে ভাগ করতে হবে যাতে প্রতিটি গ্রুপের মধ্যে বসানো জিনিসগুলি একসঙ্গে ঘুরতে পারে 
    (অর্থাৎ, চক্রাকারে ঘুরিয়ে দিলেও একই সাইকেল ধরা হবে)"
    */
    int n,k;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"S("<<n<<","<<k<<") = "<<stirling_num_first_kind( n, k);
    
}