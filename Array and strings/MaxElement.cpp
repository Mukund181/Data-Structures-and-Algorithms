#include<iostream>
#include<cmath>
using namespace std;

int findmax(int a[],int n){
    int max = a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
  return max;
}

int main(){
    int arr[] = {18,34,7,58,69,12,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = findmax(arr,n);
    cout<<max;
}