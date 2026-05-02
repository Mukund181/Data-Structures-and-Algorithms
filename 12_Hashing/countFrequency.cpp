/* Count Frequency Approach -
  Use a Hash Map (unordered_map) to store elements as keys and their occurrences as values.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void countFrequency(vector<int>& arr) {
    unordered_map<int, int> map;
    for(int x : arr) map[x]++;
    
    for(auto it : map) {
        cout << it.first << " occurs " << it.second << " times" << endl;
    }
}

// time complexity - O(N)
int main() {
    vector<int> arr = {10, 20, 20, 10, 10, 20, 5, 20};
    countFrequency(arr);
    return 0;
}
