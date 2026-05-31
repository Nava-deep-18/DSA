#include <iostream>
#include <vector>
using namespace std;
void printusingbit(vector<int>&array){
    int n=array.size();
    int subsets=1<<n;
    for(int i=0;i<subsets;i++){
        int num=i;
        for(int j=0;j<n;j++){
            if(num & (1<<j)){
                cout<<array[j]<<" ";
            }
        }
        cout<<endl;
    }
}
void printusingrec(vector<int>&array,vector<int>&ans,int i){
    if(i==array.size()){
        for(int val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(array[i]); //include
    printusingrec(array,ans,i+1);
    ans.pop_back();//back tracking step //exclude
    printusingrec(array,ans,i+1);
}
void printifsum(int s,vector<int>&ans2,int sum,vector<int>&array,int i){
    if(i==array.size()){
        if(s==sum){
            for(int val:ans2){
                cout<<val<<" ";
            }
            cout<<endl;
        }  
        return;
    }
    ans2.push_back(array[i]);
    s=s+array[i];
    printifsum(s,ans2,sum,array,i+1);
    ans2.pop_back();
    s=s-array[i];
    printifsum(s,ans2,sum,array,i+1);
}
bool printonly1ifsum(int s,vector<int>&ans2,int sum,vector<int>&array,int i){
    if(i==array.size()){
        if(s==sum){
            for(int val:ans2){
                cout<<val<<" ";
            }
            cout<<endl;
            return true;
        }  
        return false;
    }
    ans2.push_back(array[i]);
    s=s+array[i];
    if(printonly1ifsum(s,ans2,sum,array,i+1)==true){
        return true;
    }
    ans2.pop_back();
    s=s-array[i];
    if(printonly1ifsum(s,ans2,sum,array,i+1)==true){
        return true;
    }   
    return false;
}
int printcountifsum(int s,int sum,vector<int>&array,int i){
    if(i==array.size()){
        if(s==sum){
            return 1;
        }  
        return 0;
    }
    s=s+array[i];
    int l=printcountifsum(s,sum,array,i+1);
    s=s-array[i];
    int r=printcountifsum(s,sum,array,i+1);
    return l+r;
}
void subwhenduplicate(int idx,vector<int>array,vector<int>&ans,vector<vector<int>>&result){
    result.push_back(ans);
    for(int i=idx;i<array.size();i++){
        if(i!=idx && array[i]==array[i-1]) continue;
        ans.push_back(array[i]);
        subwhenduplicate(i+1,array,ans,result);
        ans.pop_back();
    }
}
int main(){
    vector<int>arr={1,2,3};
    vector<int>ans;
    printusingbit(arr);//1
    cout<<"1 completed"<<endl;
    printusingrec(arr,ans,0);//2
    cout<<"2 completed"<<endl;
    vector<int>ans2;
    int sum=3;
    printifsum(0,ans2,sum,arr,0);//3
    cout<<"3 completed"<<endl;
    vector<int>ans3;
    printonly1ifsum(0,ans3,sum,arr,0);//4
    cout<<"4 completed"<<endl;
    cout<<printcountifsum(0,sum,arr,0)<<endl;//5
    cout<<"5 completed"<<endl;
    vector<vector<int>>result;
    vector<int>ans4;
    subwhenduplicate(0,arr,ans4,result);
    for(auto v:result){
        for(int val:v){
            cout<<val;
        }
        cout<<endl;
    }
    cout<<"6 completed"<<endl;
    return 0;
}