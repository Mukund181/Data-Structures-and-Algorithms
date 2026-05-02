/* Basic Sorts Approach -
  Bubble Sort: Repeatedly swap adjacent elements if they are in wrong order.
  Selection Sort: Find min element in unsorted part, put it at beginning.
  Insertion Sort: Build sorted array one element at a time by inserting into correct position.
*/
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    cout << "Bubble: "; for(int x: arr) cout<<x<<" "; cout<<endl;
}

void selectionSort(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
    cout << "Selection: "; for(int x: arr) cout<<x<<" "; cout<<endl;
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << "Insertion: "; for(int x: arr) cout<<x<<" "; cout<<endl;
}

// time complexity - O(N^2) for all three
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    bubbleSort(arr);
    selectionSort(arr);
    insertionSort(arr);
    return 0;
}
