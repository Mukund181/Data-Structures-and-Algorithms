/* Best Time to Buy and Sell Stock Approach -
  Maintain the minimum price seen so far.
  For every day, calculate the profit if sold today (current price - min price).
  Keep track of the maximum profit.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProf = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // Buy at lowest
        } else if (price - minPrice > maxProf) {
            maxProf = price - minPrice; // Update max profit
        }
    }
    return maxProf;
}

// time complexity - O(N)
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}
