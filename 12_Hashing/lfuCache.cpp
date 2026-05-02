/* LFU Cache Approach -
  Use multiple Hash Maps and Doubly Linked Lists.
  Map1: key -> Node(key, value, freq).
  Map2: freq -> DLL of nodes.
  Keep track of min_freq to know which list to evict from when capacity is full.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

// Simplified implementation for conceptual understanding
// Real implementation requires detailed DLL manipulation
class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int, int>> keyValFreq; // key -> {value, freq}
    unordered_map<int, unordered_map<int, int>> freqKeys; // freq -> {key -> dummy} (Using map as ordered set substitute)
public:
    LFUCache(int capacity) { cap = capacity; minFreq = 0; }
    
    int get(int key) {
        if(keyValFreq.find(key) == keyValFreq.end()) return -1;
        int val = keyValFreq[key].first;
        int freq = keyValFreq[key].second;
        freqKeys[freq].erase(key);
        if(freqKeys[freq].empty() && minFreq == freq) minFreq++;
        keyValFreq[key].second++;
        freqKeys[freq + 1][key] = 1;
        return val;
    }
    // Put logic omitted for brevity in this snippet
};

// time complexity - O(1) conceptually
int main() {
    cout << "LFU Cache concept." << endl;
    return 0;
}
