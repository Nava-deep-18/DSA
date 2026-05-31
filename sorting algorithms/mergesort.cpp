#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//merge sort by divide and merge algo
void merge(vector<int>&array,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(array[left]<array[right]){
            temp.push_back(array[left]);
            left++;
        }
        else{
            temp.push_back(array[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(array[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(array[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        array[i]=temp[i-low];
    }
}
void mergesort(vector<int>&array,int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergesort(array,low,mid);
    mergesort(array,mid+1,high);
    merge(array,low,mid,high);
}
int main(){
    vector<int>vec={4,3,8,1,1,9,2,7,2};
    int n=vec.size()-1;
    mergesort(vec,0,n);
    for(int val:vec){
        cout<<val<<" ";
    }
    cout<<endl;
}