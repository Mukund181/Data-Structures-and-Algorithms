#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){  // O(n^2) time & O(1) space 
            if(arr[j]>arr[j+1]){  // compare adjacent elements
                swap(arr[j],arr[j+1]); 
            }
        }
    }
}
// note - in bubble sort the right side(max side) gets sorted first, hence 0 to n-i-1
// works by comparing adjacent elements , hence in asc, max goes to end in first step
int main(){
    int arr[]= {45,18,27,61,12,19};
    int n= sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}