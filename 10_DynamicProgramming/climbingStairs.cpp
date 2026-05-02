/* Climbing Stairs Approach -
  You can climb 1 or 2 steps. Number of ways to reach step n is (ways to reach n-1) + (ways to reach n-2).
  This is exactly the Fibonacci sequence.
*/
#include<iostream>
using namespace std;

int climbStairs(int n) {
    if(n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for(int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// time complexity - O(N), Space - O(1)
int main() {
    cout << "Ways for 5 stairs: " << climbStairs(5) << endl;
    return 0;
}
