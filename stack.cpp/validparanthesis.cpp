// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type

// Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "()[]{}"
// Output: true
// Example 3:
// Input: s = "(]"
// Output: false
// Example 4:
// Input: s = "([])"
// Output: true

#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s = "({[]}";
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='['|| s[i]=='{') st.push(s[i]);
        else{
            if(st.size()==0){
                cout<<"false"; //number of closing brackets are more
                return 0;   
            }
            if((s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{') || (s[i]==')' && st.top()=='(')) st.pop();
            else{
              cout<<"false";
              return 0;
            }
        }
    }
    if(st.size()==0){
        cout<<"true";
        return 0;
    }
    else{
        cout<<"false"; //number of opening brackets are more
        return 0;
    }
}