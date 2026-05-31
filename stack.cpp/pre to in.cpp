#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string pre = "=+F-D*C+BA";
    stack<string> st;

    for (int i = pre.size() - 1; i >= 0; i--)
    {
        if (isalnum(pre[i]))
        {
            st.push(string(1, pre[i]));  
        }
        else
        {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string s = "(" + s1 + pre[i] + s2 + ")";
            st.push(s);
        }
    }

    cout << st.top() << endl;

    return 0;
}
