#include <iostream>
#include <vector>
using namespace std;
int binarysearch(vector<int>arr,int st,int end,int target){
    int mid=st+(end-st)/2;
    if(st>end){
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return binarysearch(arr,st,mid-1,target);
    }
    else{
        return binarysearch(arr,mid+1,end,target);
    }
}
bool issorted(vector<int>arr,int n){
    if (n <= 1) {
       return true;
    }  
    if (arr[n-2] > arr[n-1]) {
        return false;
    }
    return issorted(arr, n-1);
}
int main(){
    vector<int>arr={1,3,4,5,7};
    cout<<issorted(arr,5)<<endl;
    cout<<binarysearch(arr,0,4,7)<<endl;
    return 0;
}