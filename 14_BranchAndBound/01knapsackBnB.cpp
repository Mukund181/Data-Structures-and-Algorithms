/* 0/1 Knapsack using Branch and Bound Approach -
  Use a Priority Queue to implement Least Cost Branch and Bound.
  Calculate an upper bound for the max profit possible from a node.
  If the bound is less than the current max profit, prune it.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Item { int weight, value; };
struct Node { int level, profit, weight; float bound; };

bool cmp(Item a, Item b) { return (float)a.value/a.weight > (float)b.value/b.weight; }

float bound(Node u, int n, int W, vector<Item>& arr) {
    if(u.weight >= W) return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    
    while(j < n && totweight + arr[j].weight <= W) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if(j < n) profit_bound += (W - totweight) * ((float)arr[j].value / arr[j].weight);
    return profit_bound;
}

int knapsackBnB(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    queue<Node> Q;
    Node u, v;
    u.level = -1; u.profit = u.weight = 0;
    Q.push(u);
    int maxProfit = 0;
    
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u.level == arr.size() - 1) continue;
        
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        
        if(v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;
        v.bound = bound(v, arr.size(), W, arr);
        if(v.bound > maxProfit) Q.push(v);
        
        v.weight = u.weight; v.profit = u.profit;
        v.bound = bound(v, arr.size(), W, arr);
        if(v.bound > maxProfit) Q.push(v);
    }
    return maxProfit;
}

// time complexity - Worst case O(2^N)
int main() {
    vector<Item> arr = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    cout << "Max Profit (BnB): " << knapsackBnB(10, arr) << endl;
    return 0;
}
