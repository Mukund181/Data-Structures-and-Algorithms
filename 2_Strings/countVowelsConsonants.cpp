/* Count Vowels and Consonants Approach -
  Iterate through the string, check if the character is a vowel (a, e, i, o, u).
  If it's an alphabet and not a vowel, it's a consonant.
*/
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void countVowelsConsonants(string s) {
    int v = 0, c = 0;
    for(char ch : s) {
        ch = tolower(ch);
        if(isalpha(ch)) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') v++;
            else c++;
        }
    }
    cout << "Vowels: " << v << ", Consonants: " << c << endl;
}

// time complexity - O(N)
int main() {
    countVowelsConsonants("Hello World");
    return 0;
}
