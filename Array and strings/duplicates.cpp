// for any ( sorted or unsorted array)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void finduplicates(vector<int> &arr){
    vector<int> dup;

    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); ){
            if(arr[i] == arr[j]){

                // store duplicate only once
                bool already = false;
                for(int k = 0; k < dup.size(); k++){
                    if(dup[k] == arr[i]){
                        already = true;
                        break;
                    }
                }
                if(!already){
                    dup.push_back(arr[i]);
                }

                arr.erase(arr.begin() + j);  
            }
            else{
                j++;
            }
        }
    }

    cout << "\nDuplicate Elements : ";
    for(int i = 0; i < dup.size(); i++){
        cout << dup[i] << " ";
    }

    cout << "\nAfter removing duplicates : ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector <int> arr={23,34,34,19,28,19,11,43,34,23,40};

    cout<<"Original : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    finduplicates(arr);
}