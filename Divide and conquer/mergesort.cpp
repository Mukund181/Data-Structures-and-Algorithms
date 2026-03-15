#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1;  // size of first array
    int n2= high-mid; // size of second arr, not +1 here because it starts from mid+1 --> high - (mid+1) -1 = high - mid
    int left[n1]; int right[n2];
    for(int i=0;i<n1;i++){
        left[i]= arr[low+i];  // left = arr from low to mid
    }
    for(int j=0;j<n2;j++){
        right[j]= arr[mid+1+j]; // right = arr from mid+1 to high
    }
    int i=0;
    int j=0;
    int k=low;  // arr starts from start index of left
    while(i<n1 && j<n2){ // i and j iterate through left and right
        if(left[i]<right[j]){
            arr[k++]=left[i++];
        }
        else {
            arr[k++]=right[j++];
        }
    }
    // in case scanning left/right is done and one array still has elements left
    while(i<n1){ // left ones of left in case
        arr[k++]=left[i++];
    }
    while(j<n2){ // left ones of right in case
        arr[k++]=right[j++];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){  // we cant partition when just 1 element  ,i.e low = high
      int mid=(low+high)/2;
      mergeSort(arr,low,mid);
      mergeSort(arr,mid+1,high);
      merge(arr,low,mid,high);
    }
}
int main(){
    int arr[] = {42,23,56,39,11,26,18};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high= n-1;
    mergeSort(arr,low,high);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}