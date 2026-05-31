#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<vector<int>>matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
int m=matrix.size();
int n=matrix[0].size();
int row=0;
int col=n-1;
int target;
cout<<"enter target:";
cin>>target;
while(row<m && col>=0){
    if(matrix[row][col]==target){
        cout<<"true";
        return 0;
    }
    else if(matrix[row][col]>target){
        col--;
    }
    else{
        row++;
    }
}
cout<<"false";
}