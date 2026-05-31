#include <iostream>
#include <vector>
#include<algorithm> //for sorting
using namespace std;
bool isvalid(vector<int>& stalls,int n,int m,int mid){
    int cows=1;
    int lastposition=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-lastposition>=mid){
            cows++;
            lastposition=stalls[i];
        }
        if(cows==m){
            return true;
        }
    }
    return false;
}
int aggressivecows(vector<int>& stalls,int n,int m){
    sort(stalls.begin(),stalls.end());
    int st=1;
    int end=stalls[n-1]-stalls[0];
    int ans=0;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(stalls,n,m,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>stalls={1,2,8,4,9};
    cout<<aggressivecows(stalls,5,3);
}