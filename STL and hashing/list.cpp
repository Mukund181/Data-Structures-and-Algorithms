#include <iostream>
#include <list>
using namespace std;

int main() {
    // Application: Lists are used for efficient insertions/deletions, like implementing queues, deques, or linked list problems in DSA (e.g., reversing a linked list, detecting cycles).

    // Initialization
    // 1. Empty list
    list<int> l1; // Application: Start empty for dynamic building, e.g., reading linked list from input.

    // 2. List with initializer list
    list<int> l2 = {1, 2, 3, 4, 5}; // Application: Pre-fill for known sequences, like test data.

    // 3. List with size and value
    list<int> l3(5, 10); // 5 elements of 10. Application: Initialize with defaults for counters or flags.

    // Operations on l2
    cout << "l2 elements: ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Adding elements
    l2.push_back(6); // Application: Append to end, like adding nodes in a linked list.
    l2.push_front(0); // Application: Prepend, useful in stacks or queues.
    cout << "After push_back(6) and push_front(0): ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Insert at position
    auto it = l2.begin();
    advance(it, 2); // Move to 3rd position
    l2.insert(it, 99); // Application: Insert in middle for ordered lists or priority insertions.
    cout << "After insert 99 at 3rd position: ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Erase elements
    l2.erase(it); // Erase the 99. Application: Remove specific elements, like deleting nodes in linked lists.
    cout << "After erase: ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Front and back
    cout << "Front: " << l2.front() << ", Back: " << l2.back() << endl; // Application: Access ends for queue operations.

    // Remove specific value
    l2.remove(3); // Remove all 3's. Application: Remove duplicates or specific values in lists.
    cout << "After remove(3): ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Reverse
    l2.reverse(); // Application: Reverse linked lists, common in interview problems.
    cout << "After reverse: ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Sort
    l2.sort(); // Application: Sort lists for ordered operations, like in merge sort simulations.
    cout << "After sort: ";
    for(int x : l2) cout << x << " ";
    cout << endl;

    // Size
    cout << "Size: " << l2.size() << endl;

    // Clear
    l2.clear(); // Application: Reset for multiple test cases.
    cout << "After clear, size: " << l2.size() << endl;

    // Nested List (List of Lists)
    // Application: Represent adjacency lists for graphs with multiple connections per node.
    list<list<int>> nested;
    nested.push_back({1, 2, 3});
    nested.push_back({4, 5});
    cout << "Nested List:" << endl;
    for(auto& sub : nested) {
        for(int x : sub) cout << x << " ";
        cout << endl;
    }

    return 0;
}