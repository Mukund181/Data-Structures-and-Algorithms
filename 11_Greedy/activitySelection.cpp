/* Activity Selection Approach -
  Select max activities that don't overlap.
  Sort activities by finish time. Keep picking if start time >= last finish time.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity { int start, finish; };

bool cmp(Activity a, Activity b) { return a.finish < b.finish; }

int maxActivities(vector<Activity>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    int count = 1, lastFinish = arr[0].finish;
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i].start >= lastFinish) {
            count++;
            lastFinish = arr[i].finish;
        }
    }
    return count;
}

// time complexity - O(N log N)
int main() {
    vector<Activity> arr = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    cout << "Max Activities: " << maxActivities(arr) << endl;
    return 0;
}
