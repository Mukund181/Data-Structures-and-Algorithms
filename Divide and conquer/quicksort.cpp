#include<iostream>
using namespace std;

void quicksort(int arr[],int low,int high){
       if(low<high){  
        int pivot = arr[low];
        int i=low+1;
        int j=high;
        while(i<=j){ // till the time both the pointers dont cross each other
            if(i<=high && arr[i]<pivot){    // go ahead if less than pivot
                i++;
            }
            else if(j>low && arr[j]>pivot){  // go ahead(back) if greater than pivot 
                j--;
            }
            else if(i<j){      // once pointers stopped and havent yet crossed
                swap(arr[i],arr[j]);      // swap so that greater number goes ahead and smaller comes back
            }
        }
        swap(arr[j],arr[low]);  // once i and j have crossed and stopped, put pivot to its correct position , i.e at j's
        quicksort(arr,low,j-1);   // partition array through new (correct) position of pivot
        quicksort(arr,j+1,high);   // arr[j]] is at correct pos as pivot got its correct pos
       }

     // quicksort is in place ,unstable ( orders of duplicates may get changed)
     // time complexity - best and avg - O(nlogn), worst - O(n^2) - pre sorted array and in first iteration itself the pivot is misplaced
     // recurrence eqn - T(n) = 2T(n/2) + n  --> best case
     // in general written --> T(n) = T(k) + T(n-1-k) + n --> k = no of elements on one side of pivot
     // n-1-k = no of elements on either side of pivot , n = time for partitioning the array ( single pass through array)
}
int main(){
    int arr[]= {19,27,12,2,43,21,9,36};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=n-1;
    quicksort(arr,low,high);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}