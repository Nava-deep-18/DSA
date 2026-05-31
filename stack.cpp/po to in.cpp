#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
   string po="pq+mn-*";
   stack<string>st;
    for(char ch:po){
        if(isalnum(ch)){
          st.push(string(1,ch));
        }
        else{
           string s1=st.top();st.pop();
           string s2=st.top();st.pop();
           string s="("+s2+ch+s1+')';
           st.push(s);
        }
    }
    cout<<st.top();
}