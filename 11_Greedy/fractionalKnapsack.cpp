/* Fractional Knapsack Approach -
  Sort items by value/weight ratio in descending order.
  Add items fully if capacity allows, else add fractional part.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item { int value, weight; };

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    double finalValue = 0.0;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

// time complexity - O(N log N)
int main() {
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "Max value: " << fractionalKnapsack(W, arr) << endl;
    return 0;
}
