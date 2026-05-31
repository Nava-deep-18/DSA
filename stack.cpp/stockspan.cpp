#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    vector<int>prices={100,80,60,70,60,75,85};
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<prices.size();i++){
        while(st.size()>0 && prices[st.top()]<=prices[i]){
            st.pop();
        }
        if(st.size()==0) ans.push_back(i+1); //if the element has no previous higher element
        else ans.push_back(i-st.top());
        st.push(i);
    }
    for(int val:ans){
        cout<<val<<" ";
    }
}
