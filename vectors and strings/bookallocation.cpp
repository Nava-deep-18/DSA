#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool isvalid(vector<int>arr,int n,int m,int maxallow){
  int stu=1,pages=0;
  for(int i=0;i<n;i++){
    if(arr[i]>maxallow){
        return false;
    }
  }
  for(int i=0;i<n;i++){
    if(arr[i]+pages<=maxallow){
        pages+=arr[i];
    }
    else{
       stu++;
       pages=arr[i];
    }
  }
  if(stu>m){
    return false;
  }
  else{
    return true;
  }
}
int allocatebooks(vector<int> &arr,int n,int m){
     if(m>n){
        return -1;
     }
     int sum=0;
     for(int i=0;i<n;i++){
        sum=sum+arr[i];
     }
     int ans=-1;
     int st=0,end=sum;// all possible answers
     while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
     }
     return ans;
}

int main(){
    vector<int>arr={15,17,20};
    int n=3,m=2;
    cout<<allocatebooks(arr,n,m);
    return 0;
}