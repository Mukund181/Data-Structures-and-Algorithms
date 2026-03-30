#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Application: Vectors are dynamic arrays used in problems like finding maximum subarray sum, sorting arrays, or implementing stacks/queues in DSA.

    // Initialization methods
    // 1. Empty vector
    vector<int> v1; // Application: Start with empty for dynamic input like reading array from user.

    // 2. Vector with size and default value
    vector<int> v2(5, 10); // 5 elements, each 10. Application: Initialize DP tables with default values, e.g., 0 for min/max problems.

    // 3. Vector with initializer list
    vector<int> v3 = {1, 2, 3, 4, 5}; // Application: Pre-fill with known data, like test cases or fixed arrays in problems.

    // 4. Copy from another vector
    vector<int> v4 = v3; // Application: Create copies for backtracking or recursive solutions.

    // Basic operations on v3
    cout << "v3 elements: ";
    for(int x : v3) cout << x << " ";
    cout << endl;

    // Adding elements
    v3.push_back(6); // Application: Add elements dynamically, e.g., building a list from input stream.
    cout << "After push_back(6): ";
    for(int x : v3) cout << x << " ";
    cout << endl;

    // Insert at position
    v3.insert(v3.begin() + 2, 99); // Insert 99 at index 2. Application: Insert in sorted arrays or priority queues.
    cout << "After insert at index 2: ";
    for(int x : v3) cout << x << " ";
    cout << endl;

    // Erase elements
    v3.erase(v3.begin() + 2); // Erase at index 2. Application: Remove elements in problems like removing duplicates.
    cout << "After erase at index 2: ";
    for(int x : v3) cout << x << " ";
    cout << endl;

    // Size and capacity
    cout << "Size: " << v3.size() << ", Capacity: " << v3.capacity() << endl; // Application: Check bounds in loops to avoid errors.

    // Clear vector
    v3.clear(); // Application: Reset for reuse in multiple test cases.
    cout << "After clear, size: " << v3.size() << endl;

    // 2D Vectors (Nested vectors)
    // Application: Represent matrices in graph problems, 2D DP tables, or grids in pathfinding.
    vector<vector<int>> mat(3, vector<int>(4, 0)); // 3x4 matrix initialized to 0
    mat[0][0] = 1;
    mat[1][1] = 2;
    cout << "2D Vector (Matrix):" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Vector of Pairs
    // Application: Store pairs like coordinates in geometry problems, edges in graphs, or key-value in simple maps.
    vector<pair<int, int>> vp;
    vp.push_back({1, 10});
    vp.push_back({2, 20});
    vp.push_back(make_pair(3, 30));
    cout << "Vector of Pairs:" << endl;
    for(auto p : vp) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Nested Vector of Pairs (e.g., for adjacency list in graphs)
    // Application: Represent graphs with weighted edges, like in shortest path algorithms.
    vector<vector<pair<int, int>>> graph(4); // 4 nodes
    graph[0].push_back({1, 5}); // Edge 0->1 with weight 5
    graph[0].push_back({2, 3});
    graph[1].push_back({3, 1});
    cout << "Graph (Adjacency List):" << endl;
    for(int i = 0; i < 4; i++) {
        cout << i << ": ";
        for(auto p : graph[i]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}