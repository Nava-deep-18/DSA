#include <iostream>
#include<list>
using namespace std;
class stack{
    list<int>l1;
    public:
     void push(int val){
        l1.push_front(val);
     }
     void pop(){
        l1.pop_front();
     }
     int top(){
        return l1.front();
     }
     bool empty(){
        return l1.size()==0;
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