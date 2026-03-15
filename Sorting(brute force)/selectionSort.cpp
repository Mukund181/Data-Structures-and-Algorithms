#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){   // O(n^2) time & O(1) auxillary space
            if(arr[j]<arr[min]){   // we scan entire array to find out min
                min = j;
            }
        }
        swap(arr[i],arr[min]);   // bring min to correct position
    }
}
//note - in selection sort the left side ( min side) gets sorted first, hence i+1 to n 
// works by repeatedly selecting smallest or largest and putting to correct pos
int main(){
    int arr[]= {45,18,27,61,12,19};
    int n= sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}