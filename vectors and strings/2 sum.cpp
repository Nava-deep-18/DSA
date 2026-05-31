#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int>given={5,2,11,7,15};
    int target=9;
    // // better approach
    // sort(given.begin(),given.end());
    // int st=0;
    // int size=given.size();
    // int end=size-1;
    // while(st<=end){
    //    if(given[st]+given[end]==target){
    //     cout<<given[st]<<" "<<given[end];
    //     return 0;
    //    }
    //    else if(given[st]+given[end]>target){
    //     end--;
    //    }
    //    else{
    //     st++;
    //    }
    // }

    // //most optimized method
    // //hashing
    unordered_map<int,int>m;
    for(int i=0;i<given.size();i++){
        int first=given[i];
        int second=target-first;
        if(m.find(second)!=m.end()){
            cout<<i<<" "<<m[second];
        }
        else{
            m[first]=i;
        }
    }
}

