#include<iostream>
#include<vector>
using namespace std;
class stack{
   vector<int>v;
   public:
    void push(int val){
       v.push_back(val);
    }
    void pop(){
       v.pop_back();
    }
    int top(){
       return v[v.size()-1];
    }
    bool empty(){
        if(v.size()==0) return true;
        else return false;
    }
};
int main(){
    stack s1;
    s1.push(4);
    s1.push(8);
    s1.push(32);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}