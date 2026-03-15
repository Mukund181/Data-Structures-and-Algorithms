#include<iostream>
#include<vector>
using namespace std;

int bs(int arr[],int low,int high,int key){
    if(low<=high){ // while in case of non recursive
        int mid= (low+high)/2;
        if(key==arr[mid]){
            cout<<"Element found at position "<<mid+1;
        }
        else {
            if(key>arr[mid]){
                bs(arr,mid+1,high,key);  // directly modify low,high in case of non recursive approach(while loop)
            }
            else if(key<arr[mid]){
                bs(arr,low,mid-1,key);
            }
        }
    }
}
// O(logn) time, recurrence -> T(n)=T(n/2)+1;

int main(){
    int arr[]={11,22,34,47,56,78};
    int low=0;
    int high= sizeof(arr)/sizeof(arr[0]);
    int key = 22; // to be searched
    bs(arr,low,high,key);
}