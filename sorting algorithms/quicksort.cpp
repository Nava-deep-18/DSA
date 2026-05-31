#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// divide and conquer algo
int partition(vector<int>&vec,int low,int high){
    int pivot=vec[low];
    int i=low;
    int j=high;
    while(i<j){
        while(vec[i]<=pivot && i<high){
            i++;
        }
        while(vec[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[low],vec[j]);
    return j;
}
void quicksort(vector<int>&vec,int low,int high){
    if(low<high){
        int pindex=partition(vec,low,high);
        quicksort(vec,low,pindex-1);
        quicksort(vec,pindex+1,high);
    }
}
int main(){
    vector<int>vec={4,3,8,1,1,9,2,7,2};
    int low=0;
    int high=vec.size()-1;
    quicksort(vec,low,high);
    for(int val:vec){
        cout<<val<<" ";
    }
}