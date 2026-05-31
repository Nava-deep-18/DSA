#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    unordered_map<char,int>prefer={
        {'^',3},{'*',2},{'/',2},{'+',1},{'-',1},{'(',0}
    };
    stack<char>st;
    string in="(p+q)*(m-n)";
    int n=in.length();
    string po="";
    int i=0;
    while(i<n){
        if(isalnum(in[i])){
            po.push_back(in[i]);
        }
        else if(in[i]=='('){
            st.push(in[i]);
        }
        else if(in[i]==')'){
            while(!st.empty() && st.top()!='('){
                po.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && prefer[in[i]]<=prefer[st.top()]){
                po.push_back(st.top());
                st.pop();
            }
            st.push(in[i]);
        }
        i++;
    }
    while(!st.empty()){
        po.push_back(st.top());
        st.pop();
    }
    cout<<po;
}


