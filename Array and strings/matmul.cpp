#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>mat1={{3,4,5},{6,8,9}};
    vector<vector<int>>mat2={{2,5},{8,3},{12,14}};
    int r1=mat1.size(); //no of row
    int c1=mat1[0].size();  //no of col
    int r2=mat2.size();
    int c2=mat2[0].size();
    vector<vector<int>>res={{0,0},{0,0}}; // in res-> no of cols = cols in mat2, no of rows-> rows in mat1
    if(c1=r2){  // no of col in mat1 = no of row in mat2 
        for(int i=0;i<r1;i++)         // row of mat1 * col of mat2
        {
            for(int j=0;j<c2;j++){
               for(int k=0;k<c1;k++){ //for traversing through all elements of row of mat1 & col of mat2
                res[i][j]=res[i][j]+mat1[i][k]*mat2[k][j]; // iterate same row of mat1 with col changing and iterate same col of mat2 with row changing
               }
            }
        }
    }
    
    for(int i=0;i<r1;i++){
        cout<<"\n";
        for(int j=0;j<c2;j++){
            cout<<res[i][j]<<" ";
        }
    }
}