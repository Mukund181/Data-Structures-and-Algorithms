#include<iostream>
#include<vector>
using namespace std;
void quicksort(double ratio[],vector<int>&profits,vector<int>&weights,int low,int high){
  if(low<high){
    double pivot=ratio[low];
    int i = low+1;
    int j= high;
    while(i<=j){
        if(i<=high && ratio[i]>pivot){
            i++;
        }
        else if(j>low && ratio[j]<pivot){
            j--;
        }
        else {
            swap(ratio[i],ratio[j]);
            swap(profits[i],profits[j]);
            swap(weights[i],weights[j]);
        }
    }
    swap(ratio[j],ratio[low]);
    swap(profits[j],profits[low]);
    swap(weights[j],weights[low]);
    quicksort(ratio,profits,weights,low,j-1);
    quicksort(ratio,profits,weights,j+1,high);
  }
}
double fractionalKnapsack(vector<int>profits,vector<int>weights,int capacity){
    int n = profits.size();
    double ratio[n];
    for(int i=0;i<n;i++){
        ratio[i]= (double) profits[i]/weights[i];
    }
    int low=0; int high = n-1;
    quicksort(ratio,profits,weights,low,high);
    double profit=0.0;
    for(int i=0;i<n;i++){
        if(weights[i]<capacity){
             profit = profit + profits[i];
             capacity = capacity - weights[i];
        }
        else {
            profit += profits[i] * ((double)capacity / weights[i]);
            break;
        }
    }

    return profit;
}

int main(){
    vector<int> profits = {60,100,120};
    vector<int> weights = {10,20,30};

    int capacity = 50;
    double maxProfit = fractionalKnapsack(profits,weights,capacity);
    cout<<maxProfit;
}