/* Power of Two Approach -
  A power of two has exactly one set bit.
  (n & (n - 1)) should be 0, and n > 0.
*/
#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    return (n & (n - 1)) == 0;
}

// time complexity - O(1)
int main() {
    cout << "16 is power of two: " << isPowerOfTwo(16) << endl;
    cout << "18 is power of two: " << isPowerOfTwo(18) << endl;
    return 0;
}
