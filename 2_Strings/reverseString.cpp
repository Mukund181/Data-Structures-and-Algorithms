/* Reverse String Approach -
  Use two pointers, one at the start and one at the end of the string.
  Swap characters until they meet in the middle.
*/
#include<iostream>
#include<string>
using namespace std;

void reverseString(string& s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// time complexity - O(N)
int main() {
    string s = "hello";
    reverseString(s);
    cout << "Reversed: " << s << endl;
    return 0;
}
