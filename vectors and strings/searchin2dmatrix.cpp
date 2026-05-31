// leetcode74
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m=3;
    int n=4;
    vector<vector<int>>mat={{1,3,5,7},{10,11,16,30},{23,30,34,60}};
    int target;
    cout<<"enter target:";
    cin>>target;
    int srow=0;
    int erow=m-1;
    int reqrow;
    while(srow<=erow){
        int mid=srow+(erow-srow)/2;
        if(mat[mid][0]>target){
             erow=mid-1;
        }
        else if(mat[mid][n-1]<target){
            srow=mid+1;
        }
        else if(mat[mid][0]<=target && target<=mat[mid][n-1]){
            reqrow=mid;
            break;
        }
    }
    int st=0;
    int end=n-1;
    int reqcolumn;
    while(st<=end){
       int mid=st+(end-st)/2;
       if(mat[reqrow][mid]==target){
             reqcolumn=mid;
             break;
       }
       else if(mat[reqrow][mid]>=target){
           end=mid-1;
       }
       else if(mat[reqrow][mid]<target){
            st=mid+1;
       }
    }
    cout<<reqrow+1<<" "<<reqcolumn+1;
}