#include <iostream>

using namespace std;

int countTrailingZeros(int n) {
    int count = 0;

    // Keep dividing by 5 and incrementing the count
    // until n becomes zero
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    
    /*   
       কোনো সংখ্যার ফ্যাক্টোরিয়ালের শেষে কতগুলো শূন্য থাকবে তা নির্ণয় করা।

মূল ধারণা:

কোনো সংখ্যার শেষে শূন্য আসার কারণ হলো সেই সংখ্যাটি 10 দিয়ে ভাগযোগ্য।
10 = 2 x 5। অর্থাৎ কোনো সংখ্যার ফ্যাক্টোরিয়ালে যতবার 2 এবং 5 গুণিতক থাকবে, ততবার 10 থাকবে এবং ততবার শেষে শূন্য আসবে।
সাধারণত 2 এর সংখ্যা 5 এর চেয়ে বেশি হবে। তাই শুধু 5 এর সংখ্যা গণনা করলেই চলে।
উদাহরণ:100! এর শেষে কতগুলো শূন্য থাকবে তা বের করতে হলে আমাদের 1 থেকে 100 পর্যন্ত কতগুলো 5 আছে তা গণনা করতে হবে।
সরাসরি গণনা না করে আমরা একটি সূত্র ব্যবহার করতে পারি: [n/p] + [n/p^2] + [n/p^3] + ... (যতক্ষণ না শূন্য হয়)
    
    */

    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int trailingZeros = countTrailingZeros(n);
    cout << n << "! has " << trailingZeros << " trailing zeros." << endl;

    return 0;
}