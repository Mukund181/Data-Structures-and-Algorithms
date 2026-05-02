/* Fibonacci Approach -
  Base Case: fib(0) = 0, fib(1) = 1
  Recursive step: fib(n-1) + fib(n-2)
*/
#include<iostream>
using namespace std;

int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// time complexity - O(2^N)
int main() {
    cout << "Fibonacci of 6: " << fib(6) << endl;
    return 0;
}
