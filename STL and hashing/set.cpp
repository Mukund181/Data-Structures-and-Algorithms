#include <iostream>
#include <set>
using namespace std;

int main() {
    // Application: Sets store unique, sorted elements, used in problems like finding unique elements, union operations, or implementing BSTs in DSA.

    // Initialization
    // 1. Empty set
    set<int> s1; // Application: Start empty for dynamic insertion, e.g., collecting unique items from input.

    // 2. Set with initializer list
    set<int> s2 = {5, 1, 3, 1, 5}; // Duplicates ignored, sorted. Application: Pre-fill with known unique values.

    // 3. Copy
    set<int> s3 = s2; // Application: Duplicate sets for modifications without affecting original.

    // Operations on s2
    cout << "s2 elements (sorted, unique): ";
    for(int x : s2) cout << x << " ";
    cout << endl;

    // Insert
    s2.insert(10); // Application: Add elements, like inserting into a BST.
    s2.insert(2);
    cout << "After inserts: ";
    for(int x : s2) cout << x << " ";
    cout << endl;

    // Find
    auto it = s2.find(3);
    if(it != s2.end()) {
        cout << "Found 3 at position" << endl; // Application: Check membership, e.g., in graph traversals.
    }

    // Lower bound (first >= value)
    auto lb = s2.lower_bound(3);
    if(lb != s2.end()) {
        cout << "Lower bound of 3: " << *lb << endl; // Application: Find next greater element in sorted arrays.
    }

    // Upper bound (first > value)
    auto ub = s2.upper_bound(3);
    if(ub != s2.end()) {
        cout << "Upper bound of 3: " << *ub << endl; // Application: Range queries in sorted data.
    }

    // Erase by value
    s2.erase(3); // Application: Remove specific elements, like deleting from BST.
    cout << "After erase(3): ";
    for(int x : s2) cout << x << " ";
    cout << endl;

    // Erase by iterator
    it = s2.find(5);
    if(it != s2.end()) s2.erase(it); // Application: Remove by position.
    cout << "After erase iterator to 5: ";
    for(int x : s2) cout << x << " ";
    cout << endl;

    // Size and empty
    cout << "Size: " << s2.size() << ", Empty: " << (s2.empty() ? "Yes" : "No") << endl;

    // Clear
    s2.clear(); // Application: Reset for new test cases.
    cout << "After clear, size: " << s2.size() << endl;

    // Set of pairs
    set<pair<int, int>> sp = {{1,2}, {3,4}, {1,3}}; // Application: Store unique pairs, like edges in undirected graphs.
    cout << "Set of pairs: ";
    for(auto p : sp) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // Reverse iteration
    set<int> s4 = {1,2,3,4,5};
    cout << "Reverse: ";
    for(auto rit = s4.rbegin(); rit != s4.rend(); rit++) {
        cout << *rit << " "; // Application: Traverse in reverse for specific algorithms.
    }
    cout << endl;

    return 0;
}