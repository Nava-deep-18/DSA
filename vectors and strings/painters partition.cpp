#include <iostream>
#include <vector>
#include<algorithm> //for sorting
using namespace std;
bool isvalid(vector<int>boats,int n,int m,int mid){
    for(int i=0;i<n;i++){
     if(boats[i]>mid){
         return false;
      }
    }
    int pt=1,time=0;
    for(int i=0;i<n;i++){
        if(time+boats[i]<=mid){
            time=time+boats[i];
        }
        else{
            pt++;
            time=boats[i];
        }
    }
    return pt<=m;
}

int mintime(vector<int>&boats,int n,int m){
    int sum=0;
    int mintime=INT_FAST16_MAX;
    for(int i=0;i<n;i++){
        mintime=min(mintime,boats[i]);
    }
    for(int i=0;i<n;i++){
        sum=sum+boats[i];
    }
    int st=mintime,end=sum;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(boats,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return  ans;
}
int main(){
    vector<int>boats={10,20,50,30};
    cout<<mintime(boats,4,2);
}