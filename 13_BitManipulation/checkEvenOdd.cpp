/* Check Even/Odd Approach -
  Use Bitwise AND. (num & 1) is 1 for odd, 0 for even.
*/
#include<iostream>
using namespace std;

bool isEven(int n) {
    return (n & 1) == 0;
}

// time complexity - O(1)
int main() {
    cout << "4 is even: " << isEven(4) << endl;
    cout << "5 is even: " << isEven(5) << endl;
    return 0;
}
