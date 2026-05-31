#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    int n=nums.size();
    //set<vector<int>>s;
    
    //Brute force
    
    //vector<vector<int>>ans;
    //set<vector<int>>s;
    //for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         for(int k=j+1;k<n;k++){
    //             if(nums[i]+nums[j]+nums[k]==0){
    //                 vector<int>tri={nums[i],nums[j],nums[k]};
    //                 sort(tri.begin(),tri.end());
    //                 if(s.find(tri)==s.end()){
    //                     s.insert(tri);
    //                     ans.push_back(tri);
    //                 }
    //             }
    //         }
    //     }
    // }
    
    //Hashing
    
    // for(int i=0;i<n;i++){
    //     int tar=-nums[i];
    //     set<int>s1;
    //     for(int j=i+1;j<n;j++){
    //         int th=tar-nums[j];
    //         if(s1.find(th)!=s1.end()){
    //             vector<int>v={nums[i],nums[j],th};
    //             sort(v.begin(),v.end());
    //             s.insert(v);
    //         }
    //         s1.insert(nums[j]);
    //     }
    // }
    // vector<vector<int>>ans(s.begin(),s.end());
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<3;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //most optimized method
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        while(j<k){
           int sum=nums[i]+nums[j]+nums[k];
           if(sum<0){
            j++;
           }
           else if(sum>0){
            k--;
           }
           else{
            ans.push_back({nums[i],nums[j],nums[k]});
            while (j < k && nums[j] == nums[j + 1]) j++;
            while (j < k && nums[k] == nums[k - 1]) k--;

                j++;
                k--;
           }
        }
    }    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
      
}