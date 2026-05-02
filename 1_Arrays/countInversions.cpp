/* Count Inversions Approach -
  Use an enhanced Merge Sort.
  While merging two sorted halves, if L[i] > R[j], then all elements in L after i will also be > R[j].
  Count these inversions and add them up recursively.
*/
#include<iostream>
#include<vector>
using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    long long invCount = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Crucial step
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < temp.size(); p++) {
        arr[left + p] = temp[p];
    }
    return invCount;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid, right);
    }
    return invCount;
}

// time complexity - O(N log N)
int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Inversion Count: " << mergeSort(arr, 0, arr.size() - 1) << endl;
    return 0;
}
