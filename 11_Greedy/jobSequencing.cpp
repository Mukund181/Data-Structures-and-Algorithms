/* Job Sequencing Approach -
  Sort jobs in descending order of profit.
  Iterate through jobs and place them in the latest possible available slot before their deadline.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job { int id, dead, profit; };

bool cmp(Job a, Job b) { return a.profit > b.profit; }

vector<int> JobScheduling(vector<Job>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    int n = arr.size();
    int maxi = arr[0].dead;
    for(int i = 1; i < n; i++) maxi = max(maxi, arr[i].dead);
    
    vector<int> slot(maxi + 1, -1);
    int countJobs = 0, jobProfit = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = arr[i].dead; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return {countJobs, jobProfit};
}

// time complexity - O(N log N + N * max_deadline)
int main() {
    vector<Job> arr = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> res = JobScheduling(arr);
    cout << "Jobs done: " << res[0] << ", Max Profit: " << res[1] << endl;
    return 0;
}
