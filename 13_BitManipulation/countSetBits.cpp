/* Count Set Bits Approach -
  Brian Kernighan's Algorithm: n & (n - 1) drops the lowest set bit.
  Count how many times this can be done before n becomes 0.
*/
#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// time complexity - O(Set Bits Count)
int main() {
    cout << "Set bits in 11 (1011): " << countSetBits(11) << endl;
    return 0;
}
