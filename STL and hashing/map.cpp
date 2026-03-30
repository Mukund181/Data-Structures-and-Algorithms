#include <iostream>
#include <map>
using namespace std;

int main() {
    // Application: Maps store key-value pairs in sorted order, used for frequency counts, caching, or implementing dictionaries in DSA problems.

    // Initialization
    // 1. Empty map
    map<int, string> m1; // Application: Start empty for dynamic key-value insertions, e.g., building frequency maps.

    // 2. Map with initializer list
    map<int, string> m2 = {{1, "one"}, {2, "two"}, {3, "three"}}; // Application: Pre-fill with known mappings.

    // 3. Copy
    map<int, string> m3 = m2; // Application: Duplicate maps for safe modifications.

    // Operations on m2
    cout << "m2 elements: ";
    for(auto& p : m2) cout << p.first << ":" << p.second << " ";
    cout << endl;

    // Accessing with []
    cout << "m2[1]: " << m2[1] << endl; // Application: Access values by key, like in hash tables.

    // Accessing with at() (throws exception if not found)
    try {
        cout << "m2.at(2): " << m2.at(2) << endl; // Application: Safe access with error handling.
    } catch(out_of_range& e) {
        cout << "Key not found" << endl;
    }

    // Insert
    m2.insert({4, "four"}); // Application: Add new key-value pairs, e.g., in graph representations.
    m2[5] = "five"; // Alternative insert.
    cout << "After inserts: ";
    for(auto& p : m2) cout << p.first << ":" << p.second << " ";
    cout << endl;

    // Find
    auto it = m2.find(3);
    if(it != m2.end()) {
        cout << "Found 3: " << it->second << endl; // Application: Check existence, like in membership tests.
    }

    // Lower bound
    auto lb = m2.lower_bound(3);
    if(lb != m2.end()) {
        cout << "Lower bound of 3: " << lb->first << endl; // Application: Find next key in sorted maps.
    }

    // Upper bound
    auto ub = m2.upper_bound(3);
    if(ub != m2.end()) {
        cout << "Upper bound of 3: " << ub->first << endl; // Application: Range queries.
    }

    // Erase by key
    m2.erase(3); // Application: Remove entries, like clearing cache.
    cout << "After erase(3): ";
    for(auto& p : m2) cout << p.first << ":" << p.second << " ";
    cout << endl;

    // Erase by iterator
    it = m2.find(4);
    if(it != m2.end()) m2.erase(it);
    cout << "After erase iterator: ";
    for(auto& p : m2) cout << p.first << ":" << p.second << " ";
    cout << endl;

    // Size and empty
    cout << "Size: " << m2.size() << ", Empty: " << (m2.empty() ? "Yes" : "No") << endl;

    // Clear
    m2.clear(); // Application: Reset for new data.
    cout << "After clear, size: " << m2.size() << endl;

    // Map of pairs
    map<pair<int, int>, string> mp;
    mp[{1,2}] = "point1";
    mp[{3,4}] = "point2"; // Application: Store complex keys, like coordinates to names.
    cout << "Map of pairs: ";
    for(auto& p : mp) cout << "(" << p.first.first << "," << p.first.second << "):" << p.second << " ";
    cout << endl;

    // Nested map (Map of maps)
    map<int, map<int, string>> nested;
    nested[1][10] = "a";
    nested[1][20] = "b";
    nested[2][30] = "c"; // Application: Multi-level mappings, like 2D grids with values.
    cout << "Nested map:" << endl;
    for(auto& outer : nested) {
        cout << outer.first << ": ";
        for(auto& inner : outer.second) {
            cout << inner.first << ":" << inner.second << " ";
        }
        cout << endl;
    }

    return 0;
}