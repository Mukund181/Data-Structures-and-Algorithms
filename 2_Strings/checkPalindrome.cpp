/* Check Palindrome Approach -
  Compare characters from start and end. If they don't match, it's not a palindrome.
*/
#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// time complexity - O(N)
int main() {
    string s1 = "racecar";
    string s2 = "hello";
    cout << s1 << " is palindrome: " << isPalindrome(s1) << endl;
    cout << s2 << " is palindrome: " << isPalindrome(s2) << endl;
    return 0;
}
