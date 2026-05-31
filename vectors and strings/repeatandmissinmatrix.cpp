#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    vector<vector<int>>given={{9,1,7},{8,9,2},{3,4,6}};
    int n=3;
    vector<int>ans;
    unordered_set<int>s;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             if(s.find(given[i][j])==s.end()){
                s.insert(given[i][j]);
                sum=sum+given[i][j];
            }
            else{
                ans.push_back(given[i][j]);
            }
        }
    }
    int expectedSum = (n * n * (n * n + 1)) / 2;
    int missingNumber = expectedSum - sum;
    ans.push_back(missingNumber);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}        
