#include <iostream>
#include <stack>
#include<algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
void reverse(string &s)
{
    reverse(s.begin(),s.end());
    for (char &ch : s)
    {
        if (ch == '(')
        {
            ch = ')';
        }
        else if (ch == ')')
        {
            ch = '(';
        }
    }
}
int main()
{
    unordered_map<char, int> prefer = {
        {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}};
    stack<char> st;
    string in = "F+D-C*(B+A)";
    reverse(in);
    string pre = "";
    for (char ch : in)
    {
        if (isalnum(ch))
        {
            pre.push_back(ch);
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                pre.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            if (ch == '^')
            {
                while (!st.empty() && prefer[ch] < prefer[st.top()])
                {
                    pre.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else
            {
                while (!st.empty() && prefer[ch] <= prefer[st.top()])
                {
                pre.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while(!st.empty()){
        pre.push_back(st.top());
        st.pop();
    }
    reverse(pre);
    cout<<pre;
}