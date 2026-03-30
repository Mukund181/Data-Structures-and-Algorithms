#include <iostream>
#include<vector>
#include <string>
using namespace std;

int main() {
    // Application: Strings are used for text processing, like pattern matching, parsing, or implementing string algorithms in DSA (e.g., KMP, Rabin-Karp).

    // Initialization
    // 1. Empty string
    string s1; // Application: Start empty for building strings dynamically, e.g., from input.

    // 2. From literal
    string s2 = "Hello"; // Application: Initialize with known text.

    // 3. From C-string
    string s3("World"); // Application: Convert from char arrays.

    // 4. Repeated character
    string s4(5, 'A'); // "AAAAA". Application: Initialize with patterns, like padding.

    // 5. Copy
    string s5 = s2; // Application: Duplicate strings for modifications.

    // Basic operations
    cout << "s2: " << s2 << ", length: " << s2.length() << endl;

    // Accessing characters
    cout << "s2[0]: " << s2[0] << endl; // Application: Character access for loops.

    // Concatenation
    string s6 = s2 + " " + s3; // Application: Build sentences or paths.
    cout << "Concatenated: " << s6 << endl;

    // Append
    s2.append("!!!"); // Application: Add suffixes, like in string building.
    cout << "After append: " << s2 << endl;

    // Insert
    s2.insert(5, " "); // Insert at position 5. Application: Insert characters in strings.
    cout << "After insert: " << s2 << endl;

    // Erase
    s2.erase(5, 1); // Erase 1 char at pos 5. Application: Remove parts, like trimming.
    cout << "After erase: " << s2 << endl;

    // Substring
    string sub = s6.substr(0, 5); // From 0, length 5. Application: Extract words or tokens.
    cout << "Substring: " << sub << endl;

    // Find
    size_t pos = s6.find("World");
    if(pos != string::npos) {
        cout << "Found 'World' at: " << pos << endl; // Application: Search patterns, like in string matching.
    } else {
        cout << "'World' not found" << endl;
    }

    // Find with start position
    pos = s6.find("o", 5); // Find 'o' starting from index 5.
    if(pos != string::npos) {
        cout << "Found 'o' at: " << pos << endl;
    }

    // Replace
    s6.replace(6, 5, "C++"); // Replace 5 chars from 6 with "C++". Application: Substitute text.
    cout << "After replace: " << s6 << endl;

    // Compare
    if(s2 == "Hello!!!") {
        cout << "s2 equals 'Hello!!!'" << endl; // Application: String equality checks.
    }

    // Compare lexicographically
    if(s2 < s3) {
        cout << "s2 < s3 lexicographically" << endl; // Application: Sorting strings.
    }

    // Size and empty
    cout << "Size: " << s6.size() << ", Empty: " << (s6.empty() ? "Yes" : "No") << endl;

    // Clear
    s6.clear(); // Application: Reset strings.
    cout << "After clear, size: " << s6.size() << endl;

    // Iterating
    string s7 = "ABC";
    cout << "Characters: ";
    for(char c : s7) cout << c << " "; // Application: Process each character.
    cout << endl;

    // Reverse (using algorithm)
    #include <algorithm>
    reverse(s7.begin(), s7.end()); // Application: Reverse strings, common in palindromes.
    cout << "Reversed: " << s7 << endl;

    // String of strings (vector of strings)
    vector<string> words = {"Hello", "World", "C++"}; // Application: Store multiple strings, like sentences.
    cout << "Vector of strings: ";
    for(string w : words) cout << w << " ";
    cout << endl;

    return 0;
}