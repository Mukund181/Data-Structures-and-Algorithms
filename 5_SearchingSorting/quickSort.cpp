/* Quick Sort Approach -
  Choose a pivot element. Partition array such that elements < pivot are left, elements > pivot are right.
  Recursively sort left and right partitions.
*/
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// time complexity - O(N log N) avg, O(N^2) worst
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size()-1);
    for(int x: arr) cout<<x<<" ";
    return 0;
}
