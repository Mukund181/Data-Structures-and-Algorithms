#include<iostream>
using namespace std;

int secondmax(int arr[],int n){
    int max = arr[0];
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max= arr[i];
            j = i;
        }
    }
    int s1= arr[j+1];
    int s2;
    for(int i=j+1;i<n;i++){
        if(arr[i]>s1){
            s1=arr[i];
        }
    }
    if(j==0){
        return s1;
    }
    else {
        s2 = arr[j-1];
    }
    for(int i=j-1;i>0;i++){
        if(arr[i]>s2){
            s2= arr[i];
        }
    }
    if(s1>s2){
        return s1;
    }
    else {
        return s2;
    }
}

int main(){
    int arr[]={39,89,18,20,56,32};
    int n=sizeof(arr)/sizeof(arr[0]);

    int s= secondmax(arr,n);
    cout<<s;
}