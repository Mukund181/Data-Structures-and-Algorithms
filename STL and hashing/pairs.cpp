#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    // Application: Pairs are used to store two related values, like coordinates in geometry problems, edges in graphs (u,v), or key-value in simple maps.

    // Initialization
    // 1. Using curly braces
    pair<int, string> p1 = {1, "one"}; // Application: Store index and value, e.g., in array with frequencies.

    // 2. Using make_pair
    pair<int, string> p2 = make_pair(2, "two"); // Application: Create pairs dynamically, like from function returns.

    // 3. Default initialization
    pair<int, double> p3; // Defaults to {0, 0.0}. Application: Initialize with zeros for counters.

    // 4. Copy
    pair<int, string> p4 = p1; // Application: Duplicate pairs for comparisons or modifications.

    // Accessing elements
    cout << "p1: first=" << p1.first << ", second=" << p1.second << endl;
    cout << "p2: first=" << p2.first << ", second=" << p2.second << endl;

    // Modifying
    p1.second = "ONE"; // Application: Update values, like changing labels in graph nodes.
    cout << "After modifying p1.second: " << p1.second << endl;

    // Comparing pairs
    if(p1 < p2) {
        cout << "p1 < p2 (compares first, then second)" << endl; // Application: Sort pairs, e.g., by x-coordinate in points.
    }

    // Swapping pairs
    swap(p1, p2); // Application: Exchange values, useful in sorting algorithms.
    cout << "After swap, p1: " << p1.first << "," << p1.second << endl;

    // Using tie for unpacking
    int a; string b;
    tie(a, b) = p1; // Application: Unpack pairs into variables, like extracting coordinates.
    cout << "Unpacked: a=" << a << ", b=" << b << endl;

    // Ignore with tie
    tie(ignore, b) = p2; // Ignore first, take second. Application: Extract specific parts, e.g., only y-coordinate.
    cout << "Ignored first, b=" << b << endl;

    // Pair of pairs (Nested)
    pair<int, pair<int, string>> p5 = {3, {30, "thirty"}}; // Application: Store 3D points or complex data like (id, (x,y)).
    cout << "Nested pair: " << p5.first << ", (" << p5.second.first << ", " << p5.second.second << ")" << endl;

    // Vector of pairs
    vector<pair<int, int>> points = {{1,2}, {3,4}, {5,6}}; // Application: Store list of coordinates for geometry problems like convex hull.
    cout << "Vector of pairs (points):" << endl;
    for(auto p : points) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    // Pair with different types
    pair<string, vector<int>> data = {"nums", {1,2,3}}; // Application: Store metadata with data, like name and values.
    cout << "Pair with string and vector: " << data.first << ", vector size=" << data.second.size() << endl;

    return 0;
}