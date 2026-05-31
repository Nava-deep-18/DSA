#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    Node*next;
    int data;

    Node(int val){
      data=val;
      next=NULL;
    }
};
class Queue{
    public:
    Node*head;
    Node*tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }
    void push(int data){
       Node* newnode=new Node(data);
        if(empty()){
          head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void pop(){
        if(empty()){
          cout<<"LL is empty/n";
          return;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    int front(){
        if(empty()){
            return -1;
        }
        return head->data;
    }
    bool empty(){
       return head==NULL;
    }
};
int main(){
    Queue q;
    q.push(7);
    q.push(3);
    q.push(-1);
    q.push(7);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}