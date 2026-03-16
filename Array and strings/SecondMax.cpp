#include<iostream>
using namespace std;

int secondmax(int arr[],int n){
    int max = arr[0];
        int j = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
                j = i;
            }
        }

        int s1 = -1, s2 = -1;

        // right side
        if(j != n-1){
            s2 = arr[j+1];
            for(int i = j+1; i < n; i++){
                if(arr[i] > s2 && arr[i] != max){
                    s2 = arr[i];
                }
            }
        }

        // left side
        if(j != 0){
            s1 = arr[j-1];
            for(int i = j-1; i >= 0; i--){
                if(arr[i] > s1 && arr[i] != max){
                    s1 = arr[i];
                }
            }
        }

        int ans;
        if(s1 > s2)
            ans = s1;
        else
            ans = s2;

        if(ans == -1)
            return -1;

        return ans;
    /* 
        Optimized program - ( with arr as vector)
        int largest = -1, secondLargest = -1;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] < largest && arr[i] > secondLargest){
                secondLargest = arr[i];
            }
        }

        return secondLargest;
   */

}

int main(){
    int arr[]={39,89,18,20,56,32};
    int n=sizeof(arr)/sizeof(arr[0]);

    int s= secondmax(arr,n);
    cout<<s;
}
