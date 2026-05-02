/* Randomized Set Approach -
  Insert, Delete, GetRandom in O(1).
  Use a vector for GetRandom O(1).
  Use a Hash Map (val -> index) to allow O(1) deletion from vector by swapping with last element.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> valToIdx;
public:
    bool insert(int val) {
        if(valToIdx.find(val) != valToIdx.end()) return false;
        nums.push_back(val);
        valToIdx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(valToIdx.find(val) == valToIdx.end()) return false;
        int idx = valToIdx[val];
        int lastVal = nums.back();
        nums[idx] = lastVal;
        valToIdx[lastVal] = idx;
        nums.pop_back();
        valToIdx.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

// time complexity - O(1)
int main() {
    RandomizedSet rs;
    rs.insert(1); rs.insert(2);
    cout << "Random: " << rs.getRandom() << endl;
    return 0;
}
