#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
     for(int i=1;i<n;i++){    // assume pos 0 already sorted
        int key = arr[i];    
        int j=i-1;            
        while(j>=0 && arr[j]>key){  // go on comparing the key with sorted sublist
            arr[j+1]=arr[j];   // shift to right if greater
            j--;               // move to left in sorted sublist
        }
        arr[j+1]=key;         // insert key to correct position in sorted sublist
     }
}
// O(n^2)- avg and worst case, O(n)-best case, O(1) space
//note - insertion sort works by putting each element of unsorted sublist in right to correct pos in sorted sublist in left

int main(){
    int arr[]= {45,18,27,61,12,19};
    int n= sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}