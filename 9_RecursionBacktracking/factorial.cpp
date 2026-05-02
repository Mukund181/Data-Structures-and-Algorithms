/* Factorial Approach -
  Base Case: factorial(0) = 1
  Recursive step: n * factorial(n - 1)
*/
#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// time complexity - O(N)
int main() {
    cout << "Factorial of 5: " << factorial(5) << endl;
    return 0;
}
